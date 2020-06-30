#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int arr[w.size()+1][W+1];
  for (int i = 0;i<=w.size();i++){
    arr[i][0] = 0;
  }
  for (int i = 0;i<= W;i++){
    arr[0][i] = 0;
  }
  cout << "START"<<endl;
  for (int i = 1;i<=w.size();i++){
    for (int j = 1;j <= W;j++){
      arr[i][j] = arr[i][j-1];
      if (w[j-1] <= j) {
        arr[i][j] = max(arr[i][j - w[j-1]]+1 , arr[i][j-1]);
      }
    }
  }
  for (int i = 0;i<=w.size();i++){
    for (int j = 0;j <= W;j++){
      cout << arr[i][j] << " ";
    }
    cout <<endl;
  }
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
