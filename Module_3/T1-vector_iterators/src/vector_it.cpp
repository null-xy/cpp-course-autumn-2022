#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  int i;
  while (std::cin >> i) v.push_back(i);
  return v;
}

void PrintSum1(const std::vector<int>& v) {
  int sum_1;
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end()-1; it++) {
    sum_1=*it+*(it+1);
    if(it<v.end()-2){
      std::cout << sum_1 <<" ";
    }else 
    std::cout << sum_1 << std::endl;
  }
}

void PrintSum2(const std::vector<int>& v) {
  int sum_2;
 for(unsigned i = 0; i< v.size()/2; ++i) {
      sum_2=v[i]+v[v.size()-i-1];
      if(i<v.size()/2 -1){
        std::cout << sum_2 <<" ";
      }else
      std::cout << sum_2 << std::endl;
    }
}
