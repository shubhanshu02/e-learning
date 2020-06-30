#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int arr[a.size()]={0};
  int j = 0;
  arr[0]=1;
  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] == a[i-1]) {
      arr[j]++;
    }
    else {
      j++;
      arr[j]++;
    }
    
  }
  if (*max_element(arr,arr+a.size()) > a.size()/2) return 1;
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
