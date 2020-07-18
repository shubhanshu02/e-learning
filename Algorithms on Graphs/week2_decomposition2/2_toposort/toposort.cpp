#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &visited, vector<int> &order, int x) {
  visited[x] = 1;
  for (int i = 0 ;i<adj[x].size();i++) {
    if (!visited[adj[x][i]]) dfs(adj, visited, order, adj[x][i]);
  }
  order.push_back(x);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> visited(adj.size(), 0);
  vector<int> order;
  
  for (int i = 0; i< adj.size(); i++) {
    if (visited[i] == 0) {
      dfs(adj,visited,order,i);
    }
  }
  reverse(order.begin(),order.end());
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
