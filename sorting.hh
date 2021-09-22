#include <vector>

class SortingAlgorithms {
public:
  // insertion sort
  template <typename T>
  void insertion_sort(std::vector<T>& lst) {
    for (int i=1; i < lst.size(); i++) {
      for (int j=0; j < i; j++) {
        if (lst[i] < lst[j]) {
          std::swap(lst[i], lst[j]); 
        }       
      } 
    } 
  }


};
