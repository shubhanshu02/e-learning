#include <iostream>

int get_change(int m) {
  int c =0,i=0;
  int arr[] = {10,5,1};
  while (m != 0)
  {
    int temp = m / arr[i];
    c += temp;
    m -= temp * arr[i];
    i++;
  }
  return c;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
