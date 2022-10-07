#include "pokemon.hpp"
#include <algorithm>

/*Book::Book(std::string const& name, std::string const& author,std::string const& isbn,
  bool loaned, struct Date due_date):
  name_(name),author_(author),isbn_(isbn),loaned_(loaned),due_date_(due_date){};
undefined reference to `PokemonCollection::PokemonCollection(PokemonCollection, PokemonCollection)
*/

PokemonCollection::PokemonCollection(PokemonCollection& collection,PokemonCollection& collection2){
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
//  std::list<std::pair<std::string, size_t>> pokemons_;
void PokemonCollection::SortByName(){
    /*
    std::sort(pokemons_.begin(), pokemons_.end(), 
    [](const std::pair<std::string, size_t> &x,
    const std::pair<std::string, size_t> &y)
{
    //return x.first < y.first;
});
*/
    pokemons_.sort([](auto const& a, auto const& b) {
        return a.first > b.first;
});
}
void PokemonCollection::SortById(){
    pokemons_.sort([](auto const& a, auto const& b) {
        return a.second > b.second;
});
}