#include <iostream>

long long gcd_fast(long long a, long long b) {
  if (a == 0) return b;
  else if (b == 0) return a;
  return gcd_fast(b, a%b);
}

long long lcm_naive(long long a, long long b) {
  return a*b/gcd_fast(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
