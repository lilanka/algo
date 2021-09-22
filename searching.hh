#include <vector>

class SearchingAlgorithms {
public:
  // linear search
  template <typename T>
  int linear_search(std::vector<T>& lst, T val) {
    for (int i=0; i < lst.size(); i++) {
      if (lst[i] == val) { return i; }
    } 
    return -1;
  }
};
