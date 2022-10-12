#include "magic_dragon.hpp"
#include <algorithm>
// Define MagicDragon's methods here
MagicDragon::MagicDragon(const std::string& name,size_t age, size_t size) : Dragon(name,age,size){}

void MagicDragon::Eat(std::list<Food>& food) {
    for(std::list<Food>::iterator it = food.begin(); it != food.end();it++){
        if((*it).type==FoodType::Herbs){
            std::cout <<"Magic dragon ate: "<<(*it).name<<std::endl;
            it=food.erase(it);
            this->size_=this->size_+1;
            it--;
        }
    }
 }
void MagicDragon::Hoard(std::list<Treasure>& treasure) {
    for(std::list<Treasure>::iterator it = treasure.begin(); it != treasure.end();it++){
        if((*it).type==TreasureType::Potions){
            std::cout <<"Magic dragon received: "<<(*it).name<<std::endl;
            this->treasures_.push_back(*it);
            it=treasure.erase(it);
            it--;
        }
    }
 }