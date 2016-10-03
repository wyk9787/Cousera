//
//  main.cpp
//  GreatCommonDivisor
//
//  Created by Garrett Wang on 16/7/21.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#include <iostream>

using namespace std;

long long EuclidGCD(long long a, long long b){
    if(a < b){
        long long temp = b;
        b = a;
        a = temp;
    }
    if(b == 0)
        return a;
    else{
        long long temp2 = b;
        b = a % b;
        a = temp2;
        return EuclidGCD(a, b);
    }
}

long long GCD(long long a, long long b){
    long long max = 1;
    for(long long i = 1; i < a + b; i++)
        if(a % i == 0 && b % i == 0)
            max = i;
    return max;
        
}



int main(int argc, const char * argv[]) {
    long long a, b;
    cin >> a >> b;
    cout << EuclidGCD(a, b) << endl;
    cout << GCD(a,b) << endl;
}