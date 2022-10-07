#include "pokemon.hpp"


void PokemonCollection::Add(const std::string& name, size_t id){
    pokemons_.push_back(std::make_pair(name,id));
}

bool PokemonCollection::Remove(const std::string& name, size_t id){

}

void PokemonCollection::Print() const{
    for(auto it=pokemons_.begin();it !=pokemons_.end();it++){
        std::cout << "id: " <<it ->second
        <<", name: "<<it ->first<< std::endl;
    }
    /*for(std::list<std::pair<std::string, size_t>>::iterator it=pokemons_.begin(); it!=pokemons_.end(); it++){
        std::cout << "id: " <<it ->second
        <<", name: "<<it ->first<< std::endl;
    }*/
}

void PokemonCollection::SortByName(){

}
void PokemonCollection::SortById(){

}