#include <iostream>
#include <vector>
using namespace std;

int dfs(const vector<vector<int> > adj, int start, vector<bool> visited, vector<bool> stack) {
  int n = adj.size();
  visited[start]= true;
  stack[start] = true;
  for (int i =0; i < adj[start].size(); i++) {
    if (visited[adj[start][i]] == false) {
      int x= dfs(adj, adj[start][i], visited, stack);
      if (x == 1) return 1;
    }
    else if (stack[adj[start][i]] == true) return 1;
  }
  stack[start] = false;
  return 0;
}


int acyclic(vector<vector<int> > &adj) {
  int n = adj.size();
  vector<bool> recursionstack(n,0);
  vector<bool> visited(n,0);
  for (int i=0; i<n;i++) {
    if (visited[i] == 0) {
      int x = dfs(adj, i, visited, recursionstack);
      if (x == true) return 1;
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
  }
  std::cout << acyclic(adj);
}
