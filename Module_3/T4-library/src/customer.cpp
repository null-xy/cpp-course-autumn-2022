#include "customer.hpp"
#include <iostream>
#include <algorithm>

Customer::Customer(std::string const& name, std::string const& id):name_(name),id_(id){};
std::string Customer::GetName() const{
    return name_;
}
std::string Customer::GetID() const{
    return id_;
}
int Customer::GetLoanAmount() const{
    return books_.size();
}
std::vector<Book> Customer::GetLoans() const{
    return books_;
}
bool Customer::LoanBook(Book& b){
    if(!b.GetStatus()){
    b.Loan();
    books_.push_back(b);
    return true;
    }else return false;
}
void Customer::ReturnBook(Book& b){
    if(b.GetStatus()){
        b.Restore();
        books_.erase(std::remove_if(books_.begin(), books_.end(), [b](Book& i) { return i.GetName() == b.GetName(); }), books_.end());
        /*for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
            Book book=*it;
            if (book.GetName()==b.GetName()){
                books_.erase(it);
            }
        }*/
        //books_.erase(std::remove(books_.begin(), books_.end(), b), books_.end());
    }
}

void Customer::Print() const{
    std::cout << "Customer: " <<name_
    <<", "<<id_
    <<", has "<<books_.size()
    <<" books on loan:"<< std::endl;
    for(auto i:books_){
        i.Print();
    }
    /*for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
    Book book=*it;
    std::cout <<"- Book: "<<book.GetName() 
    <<", author: "<<book.GetAuthor()
    <<", ISBN: "<<book.GetISBN()
    <<", loaned "<<std::boolalpha << book.GetStatus()
    <<", due date: " << book.GetDueDate().day<<"."<<book.GetDueDate().month<<"."<<book.GetDueDate().year
    << std::endl;
    book.Print();
    }*/
}
  /**
   *
   *
   * The output format should be like the following (for 2 loans):
   *
   * Customer: <name>, <customer_id>, has <number_of_loans> books on loan:\n
   * - Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due
   * date: <day>.<month>.<year>\n
   * - Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due
   * date: <day>.<month>.<year>\n
   *
   * (Book details must be printed on a single line)
   */