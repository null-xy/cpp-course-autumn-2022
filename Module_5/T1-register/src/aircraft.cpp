#include "aircraft.hpp"
//TODO: implement Aircraft's members
#include <string>
#include <vector>
#include <sstream>

Aircraft::Aircraft(std::string register_number, std::string owner, std::string model, double wingspan, unsigned int cruise_speed)
: Vehicle(register_number,owner),model_(model),wingspan_(wingspan),cruise_speed_(cruise_speed){}

void Aircraft::Write(std::ostream &stream){
    stream<<"A;"
    <<this->GetRegisterNumber()<<";"
    <<this->GetOwner()<<";"
    <<model_<<";"
    <<wingspan_<<";"
    <<cruise_speed_<< std::endl;
    //stream.write(reinterpret_cast<char*>(&name_), sizeof name_);
}

void Aircraft::Print(){
    std::cout<<"A;"
    <<this->GetRegisterNumber()<<";"
    <<this->GetOwner()<<";"
    <<model_<<";"
    <<wingspan_<<";"
    <<cruise_speed_
    <<std::endl;
}

Aircraft* Aircraft::Read(std::istream& stream){
    std::string line;
    std::getline(stream,line);
    if(line.front() == 'A'){
    //  std::cout << line << std::endl;
    std::vector<std::string> str_v;
    std::string str;
    std::istringstream iss(line);
    while (std::getline(iss, str, ';')) {
        str_v.push_back(str);
        }
        //for(unsigned i = 0; i< str_v.size(); ++i) {std::cout << str_v[i] << std::endl;}
    Aircraft* new_aircraft = new Aircraft(str_v[1],str_v[2],str_v[3], std::stod(str_v[4]),std::stoi(str_v[5]));
    return new_aircraft;
    }
    else{
        return NULL;
    }
}