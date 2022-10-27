#include "poly.hpp"

#include <sstream>
#include <list>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly& Poly::operator+=(const Poly& b){
    std::pair<std::map<int,int>::iterator,bool> ret;
    for (auto it = b.values_.cbegin(); it!=b.values_.cend(); it++)
    {
        ret=values_.insert(std::pair<int,int>((*it).first,(*it).second));
        if(ret.second==false){
            values_[(*it).first]=values_[(*it).first]+(*it).second;
        }
    }
    return *this;
}

Poly& Poly::operator-=(const Poly& b){
    std::pair<std::map<int,int>::iterator,bool> ret;
    Poly sub_b = -b;
    for (auto it = sub_b.values_.cbegin(); it!=sub_b.values_.cend(); it++)
    {
        ret=values_.insert(std::pair<int,int>((*it).first,(*it).second));
        if(ret.second==false){
            values_[(*it).first]=values_[(*it).first]+(*it).second;
        }
    }
    return *this;
}
std::istream& operator>>(std::istream& is, Poly& p){
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
                //-1 2 3 4 2 -2 5 2
                //-1x2+3x4+2x-2+5x2
            }
        }
        std::stringstream iss(line);
        int a,b;
        std::map<int, int> tmpmap;
        std::pair<std::map<int,int>::iterator,bool> ret;
        while (iss>>a && iss>>b)
        {
            ret = tmpmap.insert(std::pair<int,int>(b,a));
            if(ret.second==false){
                p[b]=p[b]+a;
            }else{
                p[b]=a;
            }
        }
        return is;
    }
}
std::ostream& operator<<(std::ostream& os, const Poly& p){
    std::list<std::pair<int, int>> pair_sort(p.cbegin(),p.cend());
    pair_sort.sort([](auto const& a, auto const& b)-> bool {
        return a.first > b.first;
        });
    auto newbegin=pair_sort.cbegin();
    if((*newbegin).second!=0){
        os<< (*newbegin).second << "x" << (*newbegin).first;
    }
    newbegin++;
    for (auto it = newbegin; it != pair_sort.cend(); ++it){
        if((*it).second>0){
            os<<"+"<< (*it).second << "x" << (*it).first;
        }else if((*it).second<0){
            os<< (*it).second << "x" << (*it).first;
        }
    }
    return os;
}
Poly operator+(const Poly& a, const Poly& b){
    Poly new_p(a);
    new_p +=b;
    return new_p;
}
Poly operator-(const Poly& a, const Poly& b){
    Poly new_p(a);
    new_p -=b;
    return new_p;
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
    int defalut,a_max,b_max;
    a_max = 0;
    b_max = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        defalut=it->first;
        if(defalut>=a_max || a_max == 0){
            a_max=defalut;
        }
    }
    for (auto it = b.begin(); it != b.end(); it++)
    {
        defalut=it->first;
        if(defalut>=b_max || b_max == 0){
            b_max=defalut;
        }
    }
    if(a.begin()==a.end()){
        return true;
    }else if(b.begin()==b.end()){
        return false;
    }else if(a_max<b_max){
        return true;
    }else{
        return false;
    }
}
bool operator==(const Poly& a, const Poly& b){
    std::vector<int> v_a;
    std::vector<int> v_b;
    for(auto it = a.begin(); it != a.end(); it++){
        v_a.push_back((*it).first);
    }
    for(auto it = b.begin(); it != b.end(); it++){
        v_b.push_back((*it).first);
    }
    int max_a=*std::max_element(v_a.begin(),v_a.end());
    int max_b=*std::max_element(v_b.begin(),v_b.end());
    if((max_a)==(max_b)){
        return true;
    }else{
        return false;
    }
    /*std::stringstream ssa;
    ssa<<a;
    std::string sa=ssa.str();
    std::stringstream ssb;
    ssb<<b;
    std::string sb=ssb.str();
    if(sa==sb){
        return true;
    }else{
        return false;
    }*/
    //return (std::equal(a.begin(), a.end(),b.begin(),b.end()));
}
bool operator>(const Poly& a, const Poly& b){
    int defalut,a_max,b_max;
    a_max = 0;
    b_max = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        defalut=it->first;
        if(defalut>=a_max || a_max==0){
            a_max=defalut;
        }
    }
    for (auto it = b.begin(); it != b.end(); it++)
    {
        defalut=it->first;
        if(defalut>=b_max || b_max==0){
            b_max=defalut;
        }
    }
    if(a.begin()==a.end()){
        return false;
    }else if(b.begin()==b.end()){
        return true;
    }else if(a_max>b_max){
        return true;
    }else{
        return false;
    }
}
bool operator!=(const Poly& a, const Poly& b){
    std::vector<int> v_a;
    std::vector<int> v_b;
    for(auto it = a.begin(); it != a.end(); it++){
        v_a.push_back((*it).first);
    }
    for(auto it = b.begin(); it != b.end(); it++){
        v_b.push_back((*it).first);
    }
    int max_a=*std::max_element(v_a.begin(),v_a.end());
    int max_b=*std::max_element(v_b.begin(),v_b.end());
    if((max_a)==(max_b)){
        return false;
    }else{
        return true;
    }
    /*std::stringstream ssa;
    ssa<<a;
    std::string sa=ssa.str();
    std::stringstream ssb;
    ssb<<b;
    std::string sb=ssb.str();
    if(sa==sb){
        return false;
    }else{
        return true;
    }*/
    //return !(std::equal(a.begin(), a.end(),b.begin(),b.end()));
}