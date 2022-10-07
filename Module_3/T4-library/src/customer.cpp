#include "customer.hpp"
#include <iostream>

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
    }
}
void Customer::ReturnBook(Book& b){
    b.Restore();
    for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
    Book book=*it;
    if (book.GetName()==b.GetName())
    {
        books_.erase(it);
    }
  }
}
void Customer::Print() const{
    std::cout << "Customer: " <<name_
    <<", "<<id_
    <<", has "<<books_.size()
    <<" books on loan:"<< std::endl;
    for (std::vector<Book>::const_iterator it = books_.begin(); it != books_.end(); it++) {
    Book book=*it;
    std::cout <<"- ";
    book.Print();
    }
}