#include "register.hpp"
#include <fstream>
#include <iostream>

//TODO: implement Register's members
#include "aircraft.hpp"
#include "boat.hpp"
#include <string>
#include <vector>
#include <sstream>

Register::~Register(){
    for(auto it : vehicles_){
        delete it;
        }
}

void Register::Add(Vehicle* v){
    vehicles_.push_back(v);
}

void Register::Save(const std::string& filename) const{
    std::ofstream os(filename);
    //for(auto it=vehicles_.begin(); it!=vehicles_.end(); it++){
    //size_t i
    for (unsigned i = 0; i < vehicles_.size(); i++)
    {
        //os << vehicles_.at(i)->Write();
        vehicles_.at(i)->Write(os);
    }
}

bool Register::ReadLine(std::istream& stream){
    std::string line;
    std::getline(stream,line);
    std::istringstream iss(line);
    if(line.front() == 'B'){
        vehicles_.push_back(Boat::Read(iss));
        return true;
    }else if(line.front() == 'A'){
        vehicles_.push_back(Aircraft::Read(iss));
        return true;
    }else{
        return false;
    }
}

int Register::Load(const std::string& filename){
    std::ifstream is(filename);
    if(is.rdstate() & (is.failbit | is.badbit)){
        return -1;
    }else{
        std::string line;
        //int cnt_lines=0;
        while (!is.eof() && std::getline(is, line))
        {
            //cnt_lines++;
            std::vector<std::string> str_v;
            std::string str;
            std::istringstream iss(line);
            this->ReadLine(iss);
            //std::getline(is, line);
            //std::istream iss(line);
            //iss>> line;
            //ReadLine(iss);
        }
        return vehicles_.size();
        //return cnt_lines;
    }
}

void Register::Print(){
    for (unsigned i = 0; i < vehicles_.size(); i++)
    {
        //std::cout << vehicles_.at(i) << std::endl;
        vehicles_.at(i)->Print();
    }
}

size_t Register::Size() const{
    return vehicles_.size();
}