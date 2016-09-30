//
//  main.cpp
//  Fibonaccihuge
//
//  Created by Garrett Wang on 16/7/27.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

long long get_fibonaccihuge(vector<long long> &numbers, long long n, long long i) {
    long long index;
    index = n % i;
    return numbers[index];
    return 0;
}




long long get_pisano_period(vector<long long> &numbers, long long n, long long m){
    long long count = 2;
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i = 2; i < 1000000; i++){
        numbers[i] = ((numbers[i-1] % m)+(numbers[i-2] % m)) % m;
        if(numbers[i] == 1 && numbers[i-1] == 0)
            return count-1;
        else
            count++;
    }
    return -1;
}



int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> numbers(1000000);
    long long i = get_pisano_period(numbers, n, m);
    
    cout << get_fibonaccihuge(numbers, n, i) << '\n';
    
    return 1;
}



