#include "pokemon.hpp"
#include <algorithm>

PokemonCollection::PokemonCollection(PokemonCollection collection,PokemonCollection collection2){
    collection.pokemons_.sort();
    collection.pokemons_.unique();
    collection2.pokemons_.sort();
    collection2.pokemons_.unique();
}

void PokemonCollection::Add(const std::string& name, size_t id){
    pokemons_.push_back(std::make_pair(name,id));
}

bool PokemonCollection::Remove(const std::string& name, size_t id){
    auto newEnd = std::remove_if(pokemons_.begin(), pokemons_.end(), [name,id](const auto& i) {
    return (i.first == name && i.second==id);});
    pokemons_.erase(newEnd, pokemons_.end());
    return true;
}

void PokemonCollection::Print() const{
    for(auto it=pokemons_.begin();it !=pokemons_.end();it++){
        std::cout << "id: " <<it ->second
        <<", name: "<<it ->first<< std::endl;
    }
}

void PokemonCollection::SortByName(){
    pokemons_.sort([](auto const& a, auto const& b) {
        return a.first > b.first;
});
}
void PokemonCollection::SortById(){
    pokemons_.sort([](auto const& a, auto const& b) {
        return a.second > b.second;
});
}