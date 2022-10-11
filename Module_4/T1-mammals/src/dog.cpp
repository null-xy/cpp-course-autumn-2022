#include "dog.hpp"


std::string Dog::sound_="Wuff!";

const std::string& Dog::GetName() const{
    return name_;
}

std::string& Dog::MakeSound()
{
    return sound_;
}