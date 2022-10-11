#include "cat.hpp"

Cat::Cat(const std::string& name, double weight) : Mammal(weight),name_(name){}

std::string Cat::sound_="Meow";

const std::string& Cat::GetName() const{
    return name_;
}

std::string& Cat::MakeSound()
{
    return sound_;
}