#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int> dist(adj.size(), INT32_MAX);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  //cout << "START WITH x = " << s <<endl;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    //cout << "\tPopped : " << x << endl;
    for(int i=0; i<adj[x].size(); i++){
      //cout << "NEIGHBOR CHECK" << endl;
      if (dist[adj[x][i]] == INT32_MAX) {
      //cout << "\t\tNeighbor: " << adj[x][i] << endl;
      dist[adj[x][i]] = dist[x] + 1;
      q.push(adj[x][i]);
      }
    }
  }
  /*cout << "DIST: "<<endl;
  for (auto i = dist.begin(); i!= dist.end(); i++) cout << *i << "  ";
  cout << endl;*/
  return (dist[t] != INT32_MAX)?dist[t]:-1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
