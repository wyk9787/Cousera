//
//  main.cpp
//  Fibonacci
//
//  Created by Garrett Wang on 16/7/21.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void FibonacciFast (vector<long long>& numbers, int n){
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i = 2; i < n; i++)
        numbers[i] = numbers[i-2] + numbers[i-1];
}

long long FibonacciSlow(int n){
    if(n<=1)
        return n;
    else
        return FibonacciSlow(n-1)+FibonacciSlow(n-2);
}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    FibonacciFast(numbers, n);
//    cout << FibonacciSlow(n) << endl;
    for(int i= 0; i < numbers.size(); i++)
        cout << numbers[i] << endl;;
    return 0;
}
