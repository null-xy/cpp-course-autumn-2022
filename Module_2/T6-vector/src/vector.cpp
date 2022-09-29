#include "vector.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

int GetMin(std::vector<int> v) {
  return *std::min_element(v.begin(), v.end()); 
}

int GetMax(std::vector<int> v) {
  return *std::max_element(v.begin(), v.end()); 
}

double GetAvg(std::vector<int> v) {
  double sum=std::accumulate(v.begin(), v.end(),0.0);
  int count=v.size();
  return sum/count; 
}
