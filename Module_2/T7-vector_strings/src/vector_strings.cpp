#include "vector_strings.hpp"

#include <iostream>
#include <vector>
#include <string>

void Adder(std::vector<std::string>& names) {
  std::cout << "Number of names in the vector:" << std::endl
  << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
  std::cout << "Removing the last element:" << std::endl
  << names[names.size()-1] << std::endl;
  names.erase(names.end());
}

void Printer(std::vector<std::string>& names) {
      for(int i = 0; i< names.size(); ++i) {
        std::cout << names[i] << std::endl;
    }
}

void CMDReader() {
  std::string cmd;
  cmd="default";
  std::string inputname;
  std::vector<std::string> v;

  std::cout << "Commands: ADD, PRINT, REMOVE, QUIT"
  << std::endl;
  
  while ( cmd == "QUIT" || cmd=="ADD" || cmd=="PRINT"|| cmd=="REMOVE" || cmd=="default") {
 // while ( std::cin >> cmd ) {
  std::cout << "Enter a command:"<< std::endl;
  std::cin >> cmd;
    if (cmd == "QUIT" ){
      break;
    }else if(cmd=="ADD"){
      std::cout << "Enter a name:" << std::endl;
      std::cin >> inputname;
      v.push_back(inputname);
      Adder(v);
    }else if(cmd=="PRINT"){
      Printer(v);
    }else if(cmd=="REMOVE"){
      Remover(v);
    }
     
  }
}