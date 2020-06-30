#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  vector<int> arr((str1.length()+1)*(str2.length()+1), 0);
  for (int i = 0;i<=str1.length();i++) {
    arr[i*(str2.length()+1)] = i;
  }
  for (int i = 0;i<=str2.length();i++) {
    arr[i] = i;
  }
  arr[0]=0;
  for (int i = 1;i<=str1.length();i++) {
    for (int j = 1;j<=str2.length();j++) {
      if (str1[i-1] == str2[j-1]) arr[i*(str2.length()+1)+j]= arr[(i-1)*(str2.length()+1)+j-1];
      else {
        arr[i*(str2.length()+1)+j] = min(arr[i*(str2.length()+1)+j-1] + 1, min(arr[(i-1)*(str2.length()+1)+j] + 1, arr[(i-1)*(str2.length()+1)+j-1] + 1));
      }
    }
  }

  return arr[str1.length()*(str2.length()+1)+str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
