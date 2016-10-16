#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sequence;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    
    return sequence;
}

int max_3(int a, int b, int c){
    if (a > b)
        if(a > c)
            return a;
        else
            return c;
    else
        if(b > c)
            return b;
        else
            return c;
}

int max_2(int a, int b){
    return a>b ? a : b;
}

int c(int n){
    vector<int> count(n);
    for (int i = 1; i <= n; i++){
        if (i == 1)
            count[i] = 0;
        else if (i == 2 || i == 3)
            count[i] = 1;
        else{
            if (i % 3 == 0 && i % 2 == 0)
                count[i] = max_3(count[i/3], count[i/2], count[i-1]) + 1;
            else if (i % 3 == 0)
                count[i] = max_2(count[i/3], count[i-1]) + 1;
            else if (i % 2 == 0)
                count[i] = max_2(count[i/2], count[i-1]) + 1;
            else
                count[i] = count[i-1] + 1;
        }
            
    }
}
int main() {
    int n;
    cin >> n;
    int a = c(n);
    cout << a << endl;
    cout << sequence.size()-1 << endl;
    reverse(sequence.begin(), sequence.end());
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int c(int n){
  if (n == 2)
    return 1;
  else if (n == 3)
    return 1;
  return  min (c(n/3), c(n/2), c(n-1)) + 1;


  
  
}
int main() {
  int n;
  cin >> n;
  vector<int> sequenc = optimal_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
   std::cout << sequence[i] << " ";
  }
}
