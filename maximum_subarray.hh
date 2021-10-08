#include <vector>
#include <tuple>

template <typename T>
std::tuple<int, int, T> maximum_subarray_cross(std::vector<T>& arr, int low, int mid, int high) {
  // when tha sub array is crossing the middle point
  int i = 0; int j = 0; int sum = 0;
  T left_sum = 0;
  T right_sum = 0;

  for (int a=mid; a < low; a--) {
    sum += arr[a];
    if (sum > left_sum) {
      left_sum = sum;
      i = a; 
    } 
  } 

  sum = 0;
  for (int a=mid+1; a < high; a++) {
    sum += arr[a];
    if (sum > right_sum) {
      right_sum = sum;
      j = a; 
    } 
  } 
  return std::make_tuple(i, j, left_sum + right_sum); 
}

template <typename T>
std::tuple<int, int, T> maximum_subarray(std::vector<T>& arr, int low, int high) {
  if (high == low)
    return std::make_tuple(low, high, arr[low]);

  int mid = ((low + high) % 2 == 0) ? (low + high) / 2 : (low + high + 1) / 2;
  std::tuple<int, int, T> a = maximum_subarray<T>(arr, low, mid);
  std::tuple<int, int, T> b = maximum_subarray<T>(arr, mid+1, high);
  std::tuple<int, int, T> c = maximum_subarray_cross<T>(arr, low, mid, high);
  T left_sum = std::get<2>(a);
  T right_sum = std::get<2>(b);
  T cross_sum = std::get<2>(c);

  if (left_sum >= right_sum && left_sum >= cross_sum)
    return std::make_tuple(std::get<0>(a), std::get<1>(a), left_sum);
  else if (right_sum >= left_sum && right_sum >= cross_sum)
    return std::make_tuple(std::get<0>(b), std::get<1>(b), right_sum);
  else
    return std::make_tuple(std::get<0>(c), std::get<1>(c), cross_sum);
}
