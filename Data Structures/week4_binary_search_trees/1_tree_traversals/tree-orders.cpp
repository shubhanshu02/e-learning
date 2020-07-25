#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  void in_order(int i) {
    if (i < n) {
      if (left[i] != -1) in_order(left[i]);
      cout << key[i] << " ";
      if (right[i] != -1) in_order(right[i]);
    }
    if (i == 0) cout <<endl;
  }

  void pre_order(int i) {
    if (i < n) {
      cout << key[i] << " ";
      if (left[i] != -1) pre_order(left[i]);
      if (right[i] != -1) pre_order(right[i]);
    }
    if (i == 0) cout <<endl;
  }

  void post_order(int i) {
   if (i < n) {
      if (left[i] != -1) post_order(left[i]);
      if (right[i] != -1) post_order(right[i]);
      cout << key[i] << " ";
    }
    if (i == 0) cout <<endl;
  }
};


int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order(0);
  t.pre_order(0);
  t.post_order(0);
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

