#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  struct i_d{
    long long id;
    long long free;
  };

  typedef struct i_d unit;

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

  unit my_greater(const unit a, const unit b){
   return a.free > b.free ? a : b;
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    priority_queue<unit, std::vector<unit>, std::greater<unit> > q();
    for(int i = 0; i < m; i++){
      unit u;
      u.id = i;
      u.free = 0;
      q.push_back(u);
    }
    int j = 0;
    for(int i = 0; i < m; i++){
      while(q.top().id <= i){
        assigned_workers_.push_back(q.top().id);
        start_tiems_.push_back(i);
        unit temp;
        temp.id = q.top().id;
        temp.free = q.top().free + jobs_[j];
        q.pop();
        q.push(temp);
        j++;
      }
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
