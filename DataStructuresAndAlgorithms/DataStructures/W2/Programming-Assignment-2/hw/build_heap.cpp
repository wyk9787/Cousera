#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

using namespace std;

class HeapBuilder {
private:
  vector<int> data_;
  vector<pair<int, int> > swaps_;

  int parent(int i) { return floor((i - 1) / 2); }
  int left_child(int i) { return 2 * i + 1; }
  int right_child(int i) { return 2 * i + 2; }
  void sift_down(int i) {
    int max_index = i;
    int l = left_child(i);
    if (l < data_.size() && data_[l] < data_[max_index])
      max_index = l;
    int r = right_child(i);
    if (r < data_.size() && data_[r] < data_[max_index])
      max_index = r;
    if (i != max_index) {
      swap(data_[i], data_[max_index]);
      swaps_.push_back(make_pair(i, max_index));
      sift_down(max_index);
    }
  }

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = floor(data_.size() / 2); i >= 0; i--) {
      sift_down(i);
    }
  }

public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
