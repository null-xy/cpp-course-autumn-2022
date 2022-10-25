#include "poly.hpp"

#include <sstream>
#include <list>
#include <iostream>
#include <vector>
int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly& Poly::operator+=(const Poly& b){
    //values_.
}
Poly& Poly::operator-=(const Poly& b){

}
std::istream& operator>>(std::istream& is, Poly& p){
    //20x2+10x1+5x0  -1x2+3x4+2x-2+5x2
    std::string line;
    //read is
    if(!(is>>line)){
        return is;
    }else{
        for(size_t i=0; i<line.length()-1;i++){
            if(!(std::isdigit(line[i]))){
                if(!(line[i]=='-')){
                    line[i]=' ';
                }
            }
        }
        std::stringstream iss(line);
        int a,b;
        while (iss>>a && iss>>b)
        {
            p[b]=a;
        }
        return iss;
    }
}
std::ostream& operator<<(std::ostream& os, const Poly& p){
    std::list<std::pair<int, int>> pair_sort(p.cbegin(),p.cend());
    pair_sort.sort([](auto const& a, auto const& b)-> bool {
        return a.first > b.first;
        });
    auto newbegin=pair_sort.cbegin();
    os<< (*newbegin).second << "x" << (*newbegin).first;
    newbegin++;
    for (auto it = newbegin; it != pair_sort.cend(); ++it){
        if((*it).second>=0){
            os<<"+"<< (*it).second << "x" << (*it).first;
        }else{
            os<< (*it).second << "x" << (*it).first;
        }
    }
    return os;
}
Poly operator+(const Poly& a, const Poly& b){

}
Poly operator-(const Poly& a, const Poly& b){

}
Poly operator-(const Poly& p){
    //std::map<int, int>::iterator it=p.find
    Poly newp;
    for(auto it = p.cbegin(); it !=p.cend(); it++){
        newp[(*it).first]=-(*it).second;
    }
    return newp;
}

bool operator<(const Poly& a, const Poly& b){

}
bool operator==(const Poly& a, const Poly& b){

}
bool operator>(const Poly& a, const Poly& b){

}
bool operator!=(const Poly& a, const Poly& b){
    
}