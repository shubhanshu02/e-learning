#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

size_t n;

long long max_dot_product(int a[], int b[]) {
  long long result = 0;
  for (size_t i = 0; i < n; i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}
int main() {
  
  std::cin >> n;
  int a[n], b[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  sort(a, a+n);
  sort(b, b+n);
  std::cout << max_dot_product(a, b) << std::endl;
}
