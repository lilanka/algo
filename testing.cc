#include <iostream>
#include <vector>
#include <tuple>

#include "sorting.hh"
#include "searching.hh"
#include "honers_rule.hh"
#include "maximum_subarray.hh"

int main() { 
  SortingAlgorithms sa;
  SearchingAlgorithms sea;

  std::cout << "========== insertion sort ===========" << std::endl;
  std::vector<int> x_insertion{5, 2, 4, 6, 1, 3};
  sa.insertion_sort<int>(x_insertion); 
  for (int& i: x_insertion) { std::cout << i << "\n"; }

  std::cout << "========== linear search ============" << std::endl;
  std::vector<int> x{5, 2, 4, 6, 1, 3};
  int linear_search_index = sea.linear_search<int>(x, 4);
  std::cout << linear_search_index << std::endl;

  std::cout << "========== merge sort ===========" << std::endl;
  std::vector<int> x_merge{5, 2, 4, 6, 1, 3};
  sa.merge_sort<int>(x_merge); 
  for (int& i: x_merge) { std::cout << i << "\n"; }

  std::cout << "========== bubble sort ===========" << std::endl;
  std::vector<int> x_bubble{5, 2, 4, 6, 1, 3};
  sa.merge_sort<int>(x_bubble); 
  for (int& i: x_bubble) { std::cout << i << "\n"; }

  std::cout << "========== Honer's rule ==========" << std::endl;
  int hr_out = honers_rule<int>(x, x.size(), 0, 3); 
  std::cout << hr_out << std::endl;

  std::cout << "========== maximum subarray ===========" << std::endl;
  std::vector<int> change{13, 3, 25, 20, 3, 16, 23, 18, 20, 7, 12, 5, 22, 15, 4, 7};
  std::tuple<int, int, int> set = maximum_subarray<int>(change, 0, change.size());
  std::cout << std::get<0>(set) << " " << std::get<1>(set) << " " << std::get<2>(set) << std::endl;
}
