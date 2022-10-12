#include "fantasy_dragon.hpp"
#include <algorithm>

// Define FantasyDragon's methods here
FantasyDragon::FantasyDragon(const std::string& name,size_t age, size_t size) : Dragon(name,age,size){}

void FantasyDragon::Eat(std::list<Food>& food) {
    auto it = std::find_if(food.begin(), food.end(), [](const auto& i) 
        { return (i.type == FoodType::People || i.type == FoodType::PeopleFood); });
        if((it != food.end())){
            std::cout <<"Fantasy dragon ate: "<<(*it).name<<std::endl;
            food.erase(it);
            this->size_=this->size_+1;
        }
 }
void FantasyDragon::Hoard(std::list<Treasure>& treasure) {
    //treasures_.splice(treasures_.end(), treasure);
    auto it = std::find_if(treasure.begin(), treasure.end(), [](const auto& i) 
    { return (i.type == TreasureType::Jewellery); });
    if((it != treasure.end())){
        std::cout <<"Fantasy dragon received: "<<(*it).name<<std::endl;
        this->treasures_.push_back(*it);
        treasure.erase(it);
        }
 }