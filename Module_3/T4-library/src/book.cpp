#include "book.hpp"

#include <ctime>
#include <iostream>


Book::Book(std::string const& name, std::string const& author,std::string const& isbn,
  bool loaned, struct Date due_date):
  name_(name),author_(author),isbn_(isbn),loaned_(loaned),due_date_(due_date){};

std::string Book::GetName() const{
    return name_;
}
std::string Book::GetAuthor() const{
    return author_;
}
std::string Book::GetISBN() const{
    return isbn_;
}
bool Book::GetStatus() const{
    return loaned_;
}
Date Book::GetDueDate() const{
    return due_date_;
}
bool Book::Loan(){
    loaned_= true;
    due_date_=Date::Today();
    due_date_.month=due_date_.month+1;
    return true;
}
void Book::Restore(){
    due_date_={0,0,0};
    loaned_=false;
}
void Book::Print(){
    std::cout << "Book: " <<name_
    <<", author: "<<author_
    <<", ISBN: "<<isbn_
    <<", loaned "<<loaned_
    <<", due date: "<<due_date_.day<<"."<<due_date_.month<<"."<<due_date_.year
    << std::endl;
}