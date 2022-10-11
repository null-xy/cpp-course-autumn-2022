#include "aviary.hpp"

void Aviary::Add(Bird* b){
    aviary_.push_back(b);
}

void Aviary::SpeakAll(std::ostream& os) const{
    for(auto it : aviary_){
        //os << it-> GetName() << " "; 
        it -> Speak(os);
    }
}

int Aviary::Size() const{
    return aviary_.size();//length
}

Bird * Aviary::operator[](const size_t& idx){
    //return aviary_[idx];
    return aviary_.at(idx);
}
Bird * Aviary::operator[](const size_t& idx) const{
    return aviary_.at(idx);
}

Aviary::~Aviary(){
    for(auto it : aviary_){
        delete it;
    }
}