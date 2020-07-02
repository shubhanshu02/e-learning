#include <iostream>
#include <vector>

using namespace std;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y) {
  int n = adj.size();
  bool visited[n];
  for (int i=0;i<n;i++) visited[i]=false;

  vector<int> stack;
  visited[x-1] = true;
  stack.push_back(x);
  while (!stack.empty())
  {
    int b = stack.back();
    visited[b] = true;
    stack.pop_back();
    if (b == y) return 1;
    for (int i = 0 ; i < adj[b].size() ;i++) {
      if (visited[adj[b][i]] == false) stack.push_back(adj[b][i]);
    }
  }
  
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1)<<endl;
}
