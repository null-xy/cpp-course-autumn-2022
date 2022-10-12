#include "magic_dragon.hpp"
#include <algorithm>
// Define MagicDragon's methods here
MagicDragon::MagicDragon(const std::string& name,size_t age, size_t size) : Dragon(name,age,size){}

void MagicDragon::Eat(std::list<Food>& food) {
    auto it = std::find_if(food.begin(), food.end(), [](const auto& i) 
    { return (i.type == FoodType::Herbs); });
    if((it != food.end())){
        std::cout <<"Fantasy dragon ate: "<<(*it).name<<std::endl;
        food.erase(it);
        this->size_=this->size_+1;
        }
 }
void MagicDragon::Hoard(std::list<Treasure>& treasure) {
    auto it = std::find_if(treasure.begin(), treasure.end(), [](const auto& i) 
    { return (i.type == TreasureType::Potions); });
    if((it != treasure.end())){
        std::cout <<"Fantasy dragon received: "<<(*it).name<<std::endl;
        this->treasures_.push_back(*it);
        treasure.erase(it);
        }
 }