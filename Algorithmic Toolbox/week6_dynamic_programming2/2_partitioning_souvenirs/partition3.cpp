#include <iostream>
#include <vector>

using namespace std;

int partition3(vector<int> &A, int sum) {
  int arr[sum+1][A.size()+1];
  for(int i =0;i< sum+1;i++) {
    for(int j =0;j<A.size()+1;j++) {
      arr[i][j] = 0;
    }
  }
  int count = 0;
  for(int i =1;i< sum+1;i++) {
    for(int j =1;j<A.size()+1;j++) {
      arr[i][j] = arr[i][j-1];
      if (A[j-1] <= i) {
        arr[i][j] = max(arr[i - A[j-1]][j-1] + A[j-1], arr[i][j]);
        if (arr[i][j] == sum) count++;
      }
    }
  }
  if (count < 3) return 0;
  else return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum += A[i];
  }
  if (n < 3) cout << 0 << endl;
  else if (sum % 3 != 0) cout << 0 << endl;
  else cout << partition3(A, sum/3) << '\n';
}