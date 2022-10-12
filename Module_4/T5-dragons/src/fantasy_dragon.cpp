#include "fantasy_dragon.hpp"
#include <algorithm>

// Define FantasyDragon's methods here
FantasyDragon::FantasyDragon(const std::string& name,size_t age, size_t size) : Dragon(name,age,size){}

void FantasyDragon::Eat(std::list<Food>& food) {
    for(std::list<Food>::iterator it = food.begin(); it != food.end();it++){
        if((*it).type==FoodType::People || (*it).type == FoodType::PeopleFood){
            std::cout <<"Fantasy dragon ate: "<<(*it).name<<std::endl;
            it=food.erase(it);
            this->size_=this->size_+1;
        }
    }
 }
void FantasyDragon::Hoard(std::list<Treasure>& treasure) {
    for(std::list<Treasure>::iterator it = treasure.begin(); it != treasure.end();it++){
        if((*it).type==TreasureType::Jewellery){
            std::cout <<"Fantasy dragon received: "<<(*it).name<<std::endl;
            this->treasures_.push_back(*it);
            it=treasure.erase(it);
        }
    }
    
 }