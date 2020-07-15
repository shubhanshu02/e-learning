#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using namespace std;
using std::cout;

class myComparatorforThread
{ 
public: 
    int operator() (const pair<int,int> & p1, const pair<int,int>& p2) 
    { 
      if (p1.first == p2.first) return p1.second > p2.second;
      return p1.first > p2.first; 
    } 
}; 
class JobQueue {
 private:
  int num_workers_;
  vector<long long> jobs_;

  vector<long long> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<pair<long long,long long> , vector<pair<long long,long long> >,  myComparatorforThread > threads;
    // thread - first = operation end time and second = id
    for (long long i = 0; i < num_workers_; ++i) threads.push(make_pair(0,i));
    for (long long i = 0; i < jobs_.size(); ++i) {
      long long duration = jobs_[i];
      pair<long long,long long> worker = threads.top();
      threads.pop();
      assigned_workers_[i] = worker.second;
      start_times_[i] = worker.first;
      threads.push(make_pair(worker.first+duration, worker.second));
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
