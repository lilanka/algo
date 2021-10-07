#include <vector>

template <typename T>
T honers_rule(std::vector<T>& a, int n, T y, T x) {
  if (n == 0) 
    return y;
  return honers_rule(a, n-1, a[a.size() - n] +  x * y, x);
}
