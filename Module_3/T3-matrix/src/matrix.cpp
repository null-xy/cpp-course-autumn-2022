#include "matrix.hpp"

#include <iostream>
#include <vector>

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  std::vector<std::vector<int>> m(n,std::vector<int>(n));
  for(unsigned i = 0; i < n; i++){
    for(unsigned j = 0; j < n; j++){
      std::cin >>m[i][j];
    }
  }
  return m;
  }

Matrix Rotate90Deg(const Matrix &m) {
  int n=m.size();
  std::vector<std::vector<int>> m_new(n,std::vector<int>(n));
  for(unsigned i = 0; i < n/2; i++){
    for(unsigned j = i; j < n-i-1; j++){
      m_new[i][j]=m[n-1-j][i];
      m_new[n-1-j][i]=m[n-1-i][n-1-j];
      m_new[n-1-i][n-1-j]=m[j][n-1-i];
      m_new[j][n-1-i]=m[i][j];
    }
  }
  return m_new;
  }

void Print(const Matrix &m) {
  int n=m.size();
  std::cout << "Printing out a "<< n <<" x "<< n <<" matrix:" << std::endl;
    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = 0; j < n; j++){
          std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
  }
