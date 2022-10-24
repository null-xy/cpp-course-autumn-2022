#include "boat.hpp"
//TODO: implement Boat's members
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

Boat::Boat(std::string register_number, std::string owner, std::string name, double draft, double power)
: Vehicle(register_number,owner),name_(name),draft_(draft),power_(power){}

void Boat::Write(std::ostream &stream){
    stream<<"B;"
    <<this->GetRegisterNumber()<<";"
    <<this->GetOwner()<<";"
    <<name_<<";"
    <<draft_<<";"
    <<power_<<";"<< std::endl;
    //stream.write(reinterpret_cast<char*>(&name_), sizeof name_);
}
void Boat::Print(){
    std::cout<<"B;"
    <<this->GetRegisterNumber()<<";"
    <<this->GetOwner()<<";"
    <<name_<<";"
    <<draft_<<";"
    <<power_<<";"
    <<std::endl;
}
Boat *Boat::Read(std::istream &stream){
    std::string line;
    std::getline(stream,line);
    if(line.front() == 'B'){
    //  std::cout << line << std::endl;
    std::vector<std::string> str_v;
    std::string str;
    std::istringstream iss(line);
    while (std::getline(iss, str, ';')) {
        str_v.push_back(str);
        }
        //for(unsigned i = 0; i< str_v.size(); ++i) {std::cout << str_v[i] << std::endl;}
    Boat* new_boat = new Boat(str_v[1],str_v[2],str_v[3], std::stod(str_v[4]),std::stod(str_v[5]));
    return new_boat;
    }
    else{
        return NULL;
    }
}