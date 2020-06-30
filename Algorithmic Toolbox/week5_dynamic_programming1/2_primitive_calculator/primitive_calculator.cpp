#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence[n+1];
  if (n==1) {
    vector<int> s;
    s.push_back(1);
    return s;
  }
  else if (n==2) {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    return s;
  }
  sequence[1].push_back(1);
  sequence[2].push_back(1);
  sequence[2].push_back(2);
  sequence[3].push_back(1);
  sequence[3].push_back(3);
  for (int i =4;i<=n;i++) {
    //multiply by 3
    if (i%3 == 0) {
      sequence[i] = sequence[i/3];
      sequence[i].push_back(i);
    } 
    if (i%2 == 0) {
      if (sequence[i].size() == 0) {
        sequence[i] = sequence[i/2];
        sequence[i].push_back(i);  
      }
      else if (sequence[i/2].size()+1 < sequence[i].size()) {
        sequence[i] = sequence[i/2];
        sequence[i].push_back(i);
      }
    }
    if (sequence[i].size() == 0) {
      sequence[i] = sequence[i-1];
      sequence[i].push_back(i);
    }
    else if (sequence[i-1].size()+1 < sequence[i].size()) {
      sequence[i] = sequence[i-1];
      sequence[i].push_back(i);
    }
  }
  return sequence[n];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
