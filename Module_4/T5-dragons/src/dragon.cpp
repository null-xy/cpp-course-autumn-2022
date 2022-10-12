#include "dragon.hpp"

Dragon::Dragon(const std::string& name, size_t age, size_t size)
:name_(name),age_(age),size_(size){}

const std::string& Dragon::GetName() const { return name_; }
size_t Dragon::GetAge() const { return age_; }
size_t Dragon::GetSize() const { return size_; }
const std::list<Treasure>& Dragon::GetTreasures() const { return treasures_;}
std::ostream &operator<<(std::ostream& out, const Dragon& dragon)
{
    out<<"Dragon named: "<< dragon.GetName()
    <<", age: "<< dragon.GetAge()
    <<", size: "<< dragon.GetSize()<< std::endl
    <<"Treasures:"<<std::endl;
    for(auto it : dragon.GetTreasures()){
        out<< it.name<<std::endl;
    }
    return out;
}