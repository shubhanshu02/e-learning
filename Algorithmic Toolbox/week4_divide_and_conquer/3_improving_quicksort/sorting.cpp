#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

pair<int,int> partition3(vector<int> &a, int l, int r) {
  pair<int,int> p;
  int x = a[l];
  int m1 = l, m2 = l;

  for (int i = l; i <=r; i++) {
    if (a[i] == x) {
      m2++;
    }
    else if (a[i] < x) {
      swap(a[i], a[m1]);
      m1++;
      m2++;
      if (m2 < m1) m2=m1;
    }
    else {
      swap(a[i], a[r]);
      r--;
      i--;
    }
  }
  p.first = m1;
  p.second = m2;
  return p;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int,int> x = partition3(a, l, r);
  int m1 = x.first;
  int m2 = x.second;

  randomized_quick_sort(a, l, m1-1);
  randomized_quick_sort(a, m2, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}