#include <iostream>
#include <vector>

using namespace std;

int calc_fib(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}

long long FibonacciFast (vector<long long>& numbers, int n){
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i = 2; i < n+1; i++)
        numbers[i] = numbers[i-2] + numbers[i-1];
    return numbers[n];
}

int main() {
    int n = 0;
    cin >> n;
    vector<long long> numbers(n+10);
    cout << FibonacciFast(numbers, n) << '\n';
    return 0;
}
