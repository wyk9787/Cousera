#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <ctime>

using std::vector;
using std::cin;
using std::cout;

using namespace std;

struct i_d{
    long long id;
    long long free;
};

typedef struct i_d unit;

class Compare{
public:
    bool operator()(const unit& a, const unit& b){
        if (a.free > b.free)
            return true;
        else if (a.free == b.free)
            return a.id > b.id;
        else
            return false;
    }
};

class JobQueue {
private:
    long long num_workers_;
    vector<long long> jobs_;

    vector<long long> assigned_workers_;
    vector<long long> start_times_;



    void WriteResponse() const {
        for (long long i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData(long long n, long long m, vector<long long> a) {
        // long long m;
        // cin >> num_workers_ >> m;
        num_workers_ = n;
        jobs_.resize(m);
        for(long long i = 0; i < m; ++i)
            // cin >> jobs_[i];
            jobs_[i] = a[i];
    }

    void AssignJobs() {
        // TODO: replace this code with a faster algorithm.
        priority_queue<unit, std::vector<unit>, Compare> q;
        for(long long i = 0; i < num_workers_; i++){
            unit u;
            u.id = i;
            u.free = 0;
            q.push(u);
        }
        long long j = 0;
        for(long long i = 0; i < jobs_.size(); i++){
            while(q.top().free == i){
                assigned_workers_.push_back(q.top().id);
                start_times_.push_back(i);
                unit temp;
                temp.id = q.top().id;
                temp.free = q.top().free + jobs_[j];
                q.pop();
                q.push(temp);
                j++;
            }
        }
    }

    void AssignJobs2() {
      // TODO: replace this code with a faster algorithm.
      assigned_workers_.resize(jobs_.size());
      start_times_.resize(jobs_.size());
      vector<long long> next_free_time(num_workers_, 0);
      for (int i = 0; i < jobs_.size(); ++i) {
        int duration = jobs_[i];
        int next_worker = 0;
        for (int j = 0; j < num_workers_; ++j) {
          if (next_free_time[j] < next_free_time[next_worker])
            next_worker = j;
        }
        assigned_workers_[i] = next_worker;
        start_times_[i] = next_free_time[next_worker];
        next_free_time[next_worker] += duration;
      }
    }


public:
    void Solve(long long n, long long m, vector<long long> a) {
        ReadData(n, m, a);
        AssignJobs();
        // WriteResponse();
    }

    void Solve2(long long n, long long m, vector<long long> a) {
      ReadData(n, m, a);
      AssignJobs2();
      // WriteResponse();
    }

    vector<long long> aa(){
      return assigned_workers_;
    }

    vector<long long> bb(){
      return start_times_;
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue, job_queue2;
    // job_queue.Solve1();
    srand(time(NULL));
    bool flag = true;
    while(flag){
      long long n = rand() % 100000 + 1;
      long long m = rand() % 100000 + 1;
      vector<long long> a(m);
      while(m--){
        a.push_back(rand()%1000000000+1);
      }
      job_queue.Solve(n, m, a);
      job_queue2.Solve2(n, m, a);
      vector<long long> temp1a = job_queue.aa();
      vector<long long> temp2a = job_queue.bb();
      vector<long long> temp1b = job_queue2.aa();
      vector<long long> temp2b = job_queue2.bb();
      for(long long i = 0; i < temp1a.size(); i++)
        if(temp1a[i] != temp1b[i]){
          cout << "n: " << n << endl;
          cout << "m: " << m << endl;
          for(long long i = 0; i < a.size(); i++)
            cout << a[i] << ' ';
          flag = false;
          break;
        }
      for(long long i = 0; i < temp2a.size(); i++)
        if(temp2a[i] != temp2b[i]){
          cout << "n: " << n << endl;
          cout << "m: " << m << endl;
          for(long long i = 0; i < a.size(); i++)
            cout << a[i] << ' ';
          flag = false;
          break;
        }

    }
    return 0;
}
