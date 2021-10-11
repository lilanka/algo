#include <iostream>
#include <vector>

#define N 100

// horribally slow (tree rec)
int rec_fibo(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  return rec_fibo(n - 1) + rec_fibo(n - 2);
}

// memoization (yes, you saw it wright. No R)
int F[N];

int mem_fibo(int n) {
  if (F[n] == -1) {
    if (n <= 1)
      F[n] = n; 
    else
      F[n] = mem_fibo(n-1) + mem_fibo(n-2);
  }
  return F[n];
}

void fill(int (&x)[N], int n) {
  for (int& num: x)
    num = n;
}

// dynamic programming comes to play
int iter_fibo(int n) {
  F[0] = 0; 
  F[1] = 1;
  for (int i = 2; i < n+1; i++) 
    F[i] = F[i-1] + F[i-2];
  return F[n];
}

int iter_fibo2(int n) {
  int prev = 1;
  int curr = 0;
  for (int i=1; i < n+1; i++) {
    int next = curr + prev;
    prev = curr;
    curr = next;
  }
  return curr;
}


int main() {
  int n = 5;
  std::cout << rec_fibo(n) << std::endl;
  
  fill(F, -1);
  std::cout << mem_fibo(n) << std::endl;

  fill(F, 0);
  std::cout << iter_fibo(n) << std::endl;
  std::cout << iter_fibo2(n) << std::endl;

  // todo: apply matrix method, it's faster
}
