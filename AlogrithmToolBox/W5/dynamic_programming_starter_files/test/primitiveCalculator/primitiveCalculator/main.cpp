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

int min_3(int a, int b, int c){
    if (a < b)
        if(a < c)
            return a;
        else
            return c;
    else
        if(b < c)
            return b;
        else
            return c;
}

int min_2(int a, int b){
    return a<b ? a : b;
}

int min_3k(int a, int b, int c){
    if (a < b)
        if(a < c)
            return 1;
        else
            return 3;
    else
        if(b < c)
            return 2;
        else
            return 3;
}

int min_2k(int a, int b){
    return a<b ? 1 : 2;
}

int c(int n, vector<int> &count){
    for (int i = 1; i <= n; i++){
        if (i == 1)
            count[i] = 0;
        else if (i == 2 || i == 3)
            count[i] = 1;
        else{
            if (i % 3 == 0 && i % 2 == 0)
                count[i] = min_3(count[i/3], count[i/2], count[i-1]) + 1;
            else if (i % 3 == 0)
                count[i] = min_2(count[i/3], count[i-1]) + 1;
            else if (i % 2 == 0)
                count[i] = min_2(count[i/2], count[i-1]) + 1;
            else
                count[i] = count[i-1] + 1;
        }
    }
    return count[n];
}
void sequenceBack(int n, vector<int> count){
    sequence.push_back(n);
    while(n != 1){
        if (n % 3 == 0 && n % 2 == 0){
            int j = min_3k(count[n/3], count[n/2], count[n-1]);
            if(j == 1){
                n /= 3;
            }
            else if (j == 2){
                n /= 2;
            }
            else{
                n -= 1;
            }
        }
        else if (n % 3 == 0){
            int j= min_2k(count[n/3], count[n-1]);
            if (j == 1){
                n /= 3;
            }
            else{
                n -= 1;
            }
        }
        else if (n % 2 == 0){
            int j = min_2k(count[n/2], count[n-1]);
            if(j == 1){
                n /= 2;
            }
            else{
                n -= 1;
            }
        }
        else{
            n -= 1;
        }
        sequence.push_back(n);
        
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> count(n+1);
    int a = c(n, count);
    cout << a << endl;
    sequenceBack(n, count);
    reverse(sequence.begin(), sequence.end());
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
