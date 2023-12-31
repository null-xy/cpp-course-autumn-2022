#include "pokemon.hpp"
#include <algorithm>

PokemonCollection::PokemonCollection(PokemonCollection collection,PokemonCollection collection2)
{
    pokemons_=collection.pokemons_;
    pokemons_.merge(collection2.pokemons_);
    pokemons_.sort();
    pokemons_.unique();
}

void PokemonCollection::Add(const std::string& name, size_t id){
    pokemons_.push_back(std::make_pair(name,id));
}

bool PokemonCollection::Remove(const std::string& name, size_t id){
    std::list<std::pair<std::string, size_t>>::const_iterator 
    it = std::find_if(pokemons_.begin(), pokemons_.end(), [name,id](const auto& i) 
        { return (i.first == name && i.second==id); });
    /*auto it = std::remove_if(pokemons_.begin(), pokemons_.end(), [name,id](const auto& i) 
        { return (i.first == name && i.second==id); });pokemons_.erase(it, pokemons_.end());//remove all
    //pokemons_.erase(std::remove_if(pokemons_.begin(), pokemons_.end(), [name,id](const auto& i) 
    //    { return (i.first == name && i.second==id); }), pokemons_.end());
    */
    if (it != pokemons_.end()){
        pokemons_.erase(it);
        return true;
    }
    else{
        return false;
    }
}

void PokemonCollection::Print() const{
    for(auto it=pokemons_.begin();it !=pokemons_.end();it++){
        std::cout << "id: " <<it ->second
        <<", name: "<<it ->first<< std::endl;
    }
}

void PokemonCollection::SortByName(){
    pokemons_.sort([](auto const& a, auto const& b)-> bool {
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
});
}
void PokemonCollection::SortById(){
    pokemons_.sort([](auto const& a, auto const& b) {
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });
}