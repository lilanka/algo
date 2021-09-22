#include <iostream>
#include <vector>

#include "sorting.hh"
#include "searching.hh"

int main() { 
  std::vector<int> x{5, 2, 4, 6, 1, 3};

  std::cout << "========== insertion sort ===========" << std::endl;
  SortingAlgorithms sa;
  sa.insertion_sort<int>(x); 
  for (int& i: x) { std::cout << i << "\n"; }

  std::cout << "========== linear search ============" << std::endl;
  SearchingAlgorithms sea;
  int linear_search_index = sea.linear_search<int>(x, 4);
  std::cout << linear_search_index << std::endl;
}
