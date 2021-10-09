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

  template <typename T>
  int partition(std::vector<T>& A, int p) {
    std::swap(A[p], A[-1]); 
    int l = 0;
    for (int i=0; i < n; i++) {
      if (A[i] < A[A.size()-1]) {
        l++;
        std::swap(A[l], A[i]);  
      } 
    }
    std::swap(A[A.size()-1], A[l+1]);
    return l+1;
  }
};
