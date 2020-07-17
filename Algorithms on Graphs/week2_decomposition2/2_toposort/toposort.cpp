#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &visited, vector<int> &order, int x) {
  vector<int> stack;
  stack.push_back(x);
  vector<int> s;
  while(!stack.empty()) {
    int b = stack.back();
    stack.pop_back();
    for (int i =0; i < adj[b].size();i++) {
      if (visited[adj[b][i]] == 0) stack.push_back(adj[b][i]); 
    }
    if (visited[b] == 0) {
      s.push_back(b);
      }
    visited[b] = 1;
    
  }
  reverse(s.begin(),s.end());
  for (int i =0; i< s.size();i++) {
    order.push_back(s[i]);
    }
  //write your code here
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> visited(adj.size(), 0);
  vector<int> order;
  
  for (int i = 0; i< adj.size(); i++) {
    sort(adj[i].rbegin(),adj[i].rend());
  }

  for (int i = 0; i< adj.size(); i++) {
    if (visited[i] == 0) {
      dfs(adj,visited,order,i);
    }
  }
  reverse(order.begin(), order.end());
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
