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

  // merge sort
  template <typename T>
  void merge_sort(std::vector<T>& lst) {
    mergeSort<T>(lst, 0, lst.size()-1); 
  }

  template <typename T>
  void merge(std::vector<T>& lst, int a, int c, int b) {
    int tmp[b + 1];
    int i = a;
    int j = c + 1;
    int k = 0;
    
    while (i <= c && j <= b) {
      if (lst[i] <= lst[j])
        tmp[k++] = lst[i++];
      else
        tmp[k++] = lst[j++];
    } 
    while (i <= c)
      tmp[k++] = lst[i++];
    while (j <= b)
      tmp[k++] = lst[j++];
    k--;
    while (k >= 0) {
      lst[k+a] = tmp[k];
      k--; 
    }
  }

  template <typename T> 
  void mergeSort(std::vector<T>& lst, int a, int b) {  
    int c; // mid value
    if (a < b) {
      c =  (a + b) / 2;
      mergeSort(lst, a, c);
      mergeSort(lst, c + 1, b);
      merge(lst, a, c, b);
    } 
  }
  
  // bubble sort
  template <typename T>
  void bubble_sort(std::vector<T>& lst) {
    for (int i=0; i < lst.size(); i++) {
      for (int j=lst.size()-1; j > i+1; i--) {
        if (lst[j] < lst[j - 1])
          std::swap(lst[j], lst[j-1]); 
      } 
    } 
  }
};
