#include "list.hpp"

#include <iostream>
#include <string>
#include <sstream>

// Implement the functions here

std::istream& GetLines(std::istream& is, std::list<std::string>& list) {
    list.clear();
    std::string temp;
    while(std::getline(is, temp)){
        list.push_back(temp);
    }
    return is;
}

void Print(const std::list<std::string>& list) {
    for (const auto& i : list)
    std::cout << i << std::endl;
}

void SortAndUnique(std::list<std::string>& list) {
    list.sort();
    list.unique();
}