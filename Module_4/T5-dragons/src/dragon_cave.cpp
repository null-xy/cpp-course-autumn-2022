#include "dragon_cave.hpp"
#include <algorithm>

// Define DragonCave's methods here
DragonCave::~DragonCave(){
    for(auto it : dragons_){
        delete it;
    }
}
const std::list<Dragon*> DragonCave::GetDragons() const{
    return this->dragons_;
}
void DragonCave::Accommodate(Dragon* dragon){
    dragons_.push_back(dragon);
}
std::ostream &operator<<(std::ostream& out, const DragonCave& cave){
    out<<"DragonCave dwellers:"<<std::endl;
    //auto newend=dragon.GetTreasures().end();
    //newend--;
    for(auto it : cave.GetDragons()){
        out<<std::endl<< *it;
    }
    return out;
}
/*    for(auto it = dragon.GetTreasures().begin();it != newend;it++ ){
        out<< it->name<<std::endl;
    }
    //out<< dragon.GetTreasures().end()->name;
    out<< newend->name;*/
void DragonCave::Evict(const std::string& name){
    auto it = std::find_if(dragons_.begin(), dragons_.end(), [name](const auto& i) 
    { return (i->GetName() == name); });
    if((it != dragons_.end())){
        dragons_.erase(it);
        }
}