#include <iostream>
#include <vector>


using namespace std;

long long get_fibonaccihuge(vector<long long> &numbers, long long n) {
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i = 2; i < n+1; i++)
        numbers[i] = (numbers[i-2] + numbers[i-1]) % 10;
    return numbers[n];
    
}

int main() {
    int n = 0;
    cin >> n;
    vector<long long> numbers(n+10);
    cout << get_fibonaccihuge(numbers, n) << '\n';
    return 0;
}


