#include "library.hpp"

#include <iostream>
#include <algorithm>
#include "book.hpp"
#include "customer.hpp"


Library::Library(std::string const& name):name_(name){};
std::string Library::GetName() const{
    return name_;
}
std::vector<Book>& Library::GetBooks(){
    return books_;
}
std::vector<Customer>& Library::GetCustomers(){
    return customers_;
}
Book Library::FindBookByName(std::string const& name){
    Book book("","","");
    for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
        Book book_loop=*it;
        if (book_loop.GetName()== name){
            book=*it;
        }
    }
  return book;
}
std::vector<Book> Library::FindBooksByAuthor(std::string const& name){
    std::vector<Book> found_books;
    for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
        Book book=*it;
        if (book.GetAuthor()==name){
            found_books.push_back(book);
        }
    }
    return found_books;
}
std::vector<Book> Library::FindAllLoanedBooks(){
    std::vector<Book> loaned_books;
    for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
        Book book=*it;
        if (book.GetStatus()){
            loaned_books.push_back(book);
        }
    }
    return loaned_books;
}
Customer Library::FindCustomer(std::string const& id){
    Customer customer("","");
    for (std::vector<Customer>::const_iterator it = customers_.begin(); it != customers_.end(); it++) {
        Customer customer_loop=*it;
        if(customer_loop.GetID()==id){
            customer=*it;
        }
    }
    return customer;
}