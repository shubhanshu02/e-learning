#include <iostream>
#include <vector>

using namespace std;
using std::pair;

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  int n = adj.size();
  bool visited[n];
  for (int i=0;i<n;i++) visited[i]=false;

  for (int i=0;i<n;i++) {
    if (visited[i] == false) {
      vector<int> stack;
      visited[i] = true;
      stack.push_back(i);
      while (!stack.empty())
      {
        int b = stack.back();
        visited[b] = true;
        stack.pop_back();
        for (int i = 0 ; i < adj[b].size() ;i++) {
          if (visited[adj[b][i]] == false) stack.push_back(adj[b][i]);
        }
      }
      res++;
    }
  }
  return res;
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
  std::cout << number_of_components(adj) << endl;
}
