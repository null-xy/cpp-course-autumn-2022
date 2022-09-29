#include "person.hpp"

// define your Person class' functions here

Person::Person(const std::string& name, const int birthyear)
: name_(name),birthyear_(birthyear),age_(0){
}

const std::string& Person::GetName() const{
    return name_;
}
int Person::GetAge(int currentyear){
    age_= currentyear - birthyear_;
    return age_;
}