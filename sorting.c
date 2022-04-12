#include <stdio.h>
#include <stdbool.h>

void debug_array(int A[7], const int n, char* word, const bool is_reverse) {
  int validation[7] = {0, 1, 2, 4, 5, 33, 75};
  if (!is_reverse) {
    for (int i=0; i < n; ++i) {
      if (A[i] != validation[i]) {
        printf("%s: %s\n", word, "Order incorrect"); return;
      }
    }
    printf("%s: %s\n", word, "Order correct");
  } else {
    for (int i=0; i < n; ++i) { 
      if (A[i] != validation[n-i-1]) {
        printf("%s: %s\n", word, "Order incorrect"); return;
      }
    }
    printf("%s: %s\n", word, "Order correct");
  }  
}

void insertion_sort_reverse(int A[7], const int n) {
  for (int i = 1; i < n; ++i) {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] < key) {
      A[j+1] = A[j];
      j -= 1;
    }
    A[j+1] = key;
  }
  debug_array(A, 7, "Insertion sort reverse", true);
}

void insertion_sort(int A[7], const int n) {
  for (int i = 1; i < n; ++i) {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j -= 1;
    }
    A[j+1] = key;
  }
  debug_array(A, 7, "Insertion sort", false);
}

int main(void) {
  int A[7] = {4, 5, 2, 1, 0, 75, 33};

  // insertion sort 
  insertion_sort(A, 7);

  // insertion sort reverse
  insertion_sort_reverse(A, 7);
}
