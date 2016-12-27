#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

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

    void ReadData() {
        long long m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(long long i = 0; i < m; ++i)
            cin >> jobs_[i];
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
                temp.free = i + jobs_[j];
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
