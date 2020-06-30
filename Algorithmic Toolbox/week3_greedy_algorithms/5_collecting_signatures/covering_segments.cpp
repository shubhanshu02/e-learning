#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<int> optimal_points(vector<pair<int, int> > &segments) {
  vector<int> points;
  //write your code here
  int done[segments.size()] = {0};

  for (size_t i = 0; i < segments.size(); ++i) {
    if (done[i] == 1) continue;

    done[i]=1;

    for(int j=i+1;j < segments.size(); ++j) {
      if (segments[j].first >= segments[i].first && segments[j].second <= segments[i].first) {
        done[j] = 1;
      }
    }
    
    points.push_back(segments[i].first);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<pair<int,int> > segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].second >> segments[i].first;
  }
  sort(segments.begin(), segments.end());
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  cout << endl;
}
