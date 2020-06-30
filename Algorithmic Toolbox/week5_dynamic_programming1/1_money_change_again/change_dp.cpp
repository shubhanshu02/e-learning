#include <iostream>
using namespace std;
int arr[] = {4,3,1};

int get_change(int m) {
  //write your code here
  int mini[m+1] = {0};
  for (int i = 1;i<=m;i++) {
    mini[i] = 10000;
  }
  for (int i = 1;i<=m;i++) {
    for(int j =0;j<3;j++) {
      if (i >= arr[j]) {
        mini[i] = min(mini[i], mini[i-arr[j]]+1);
      }
    }
  }
  return mini[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
