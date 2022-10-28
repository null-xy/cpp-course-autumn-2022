
#include "printers.hpp"
#include <algorithm>

Printers::~Printers(){
    //for(auto it : stringPrinter_){
        //delete *(*it).first;
        //delete it.second;
    //}
    for(std::vector<std::pair<std::string, StringPrinter*>>::iterator 
    it = stringPrinter_.begin(); it != stringPrinter_.end();it++){
        delete (*it).second;
    }

}
Printers::Printers(const Printers& other){
    //stringPrinter_=other.stringPrinter_;
    for(std::vector<std::pair<std::string, StringPrinter*>>::const_iterator 
    it = other.stringPrinter_.cbegin(); it != other.stringPrinter_.cend();it++)
    {
        std::string new_name =(*it).first;
        stringPrinter_.push_back(std::make_pair(new_name,(*it).second->Clone()));
    }
}
Printers& Printers::operator=(const Printers& other){
    //stringPrinter_=other.stringPrinter_;
    for(std::vector<std::pair<std::string, StringPrinter*>>::const_iterator 
    it = other.stringPrinter_.cbegin(); it != other.stringPrinter_.cend();it++)
    {
        std::string new_name =(*it).first;
        stringPrinter_.push_back(std::make_pair(new_name,(*it).second->Clone()));
    }
    return *this;
}
void Printers::Add(const std::string& name, StringPrinter* printer){
    std::vector<std::pair<std::string, StringPrinter*>>::const_iterator
    it=std::find_if(stringPrinter_.cbegin(), stringPrinter_.cend(), [name](const auto& i) 
        { return (i.first == name); });
    if(it != stringPrinter_.end()){
        throw std::invalid_argument("Duplicate index");
    }else if(printer==nullptr){
        throw std::invalid_argument("Invalid printer");
    }else{
        stringPrinter_.push_back(std::make_pair(name,printer));
    }
}
StringPrinter& Printers::operator[](const std::string& name){
    std::vector<std::pair<std::string, StringPrinter*>>::const_iterator
    it=std::find_if(stringPrinter_.cbegin(), stringPrinter_.cend(), [name](const auto& i) 
        { return (i.first == name); });
    if (it == stringPrinter_.end()){
        throw std::invalid_argument("Unknown index");
    }else{
        return *((*it).second);
    }
}