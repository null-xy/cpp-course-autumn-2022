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
        books_.erase(std::remove_if(books_.begin(), books_.end(), [b](Book& i) 
        { return i.GetName() == b.GetName(); }), books_.end());
    }
}

void Customer::Print() const{
    std::cout << "Customer: " <<name_
    <<", "<<id_
    <<", has "<<books_.size()
    <<" books on loan:"<< std::endl;
    for(auto i:books_){
        std::cout <<"- ";
        i.Print();
    }
}