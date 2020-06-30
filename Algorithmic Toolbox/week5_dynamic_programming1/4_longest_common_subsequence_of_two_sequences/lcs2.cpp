#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  int arr[a.size()+1][b.size()+1];
  for (int i = 0;i<=a.size();i++) {
    arr[i][0] = 0;
  }
  for (int i = 0;i<=b.size();i++) {
    arr[0][i] = 0;
  }
  arr[0][0]=0;
  for (int i = 1;i<=a.size();i++) {
    for (int j = 1;j<=b.size();j++) {
      if (a[i-1] == b[j-1]) arr[i][j]= arr[i-1][j-1]+1;
      else {
        arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
      }
    }
  }
  return arr[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
