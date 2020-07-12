#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using namespace std;
using std::cout;
int parent(int i) {
    return (i-1)/2;
}
int leftchild(int i) {
    return 2*i+1;
}
int rightchild(int i) {
    return 2*i+2;
}
class myComparator 
{ 
public: 
    int operator() (const pair<int,int> & p1, const pair<int,int>& p2) 
    { 
        return p1.first > p2.first; 
    } 
}; 

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
  vector<int> jobs_;

  vector<int> assigned_workers_;
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
    priority_queue<pair<long long,long long> , vector<pair<long long,long long> >,  myComparatorforThread > q;
    for (long long i=0;i<jobs_.size();i++) {
      q.push(make_pair(jobs_[i], i));
    }
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<pair<long long,long long> , vector<pair<long long,long long> >,  myComparatorforThread > threads;
    // thread - first = start time and second = id
    for (long long i = 0; i < num_workers_; ++i) threads.push(make_pair(0,i));
    for (long long i = 0; i < jobs_.size(); ++i) {
      auto p = q.top();
      q.pop();
      
      long long current_job = p.second;
      long long duration = p.first;
      auto worker = threads.top();
      threads.pop();
      assigned_workers_[current_job] = worker.second;
      start_times_[current_job] = worker.first;
      threads.push(make_pair(worker.first+duration, worker.second));
      /* 
      if (threads.size() != num_workers_) {
        
        assigned_workers_[current_job] = threads.size();
        start_times_[current_job] = 0;
        threads.push(duration);
      }
      else {
        auto starting = threads.top();
        threads.pop();
        assigned_workers_[current_job] = 0;
        start_times_[current_job] = starting;
        threads.push(starting+duration);
      } */
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
