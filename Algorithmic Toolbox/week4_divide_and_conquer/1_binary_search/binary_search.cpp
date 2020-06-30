#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1; 
  //write your code here
  while (left <= right) {
    int mid = left + (right-left)/2;
    //cout <<"\t\tTRY WITH x="<< x<<" "<<mid << " " << left << " "<<right<<endl;
    if (a[mid] == x) return mid;
    if (right-left == 1) left=right;
    else if (right==left) break;
    else if (a[mid] < x) left = mid;
    else right = mid;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cout << binary_search(a, b[i]) << ' ';
  }
}
