//
//  main.cpp
//  MaximizeValue
//
//  Created by Garrett Wang on 11/15/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

long long min4(long long a, long long b, long long c, long long d, long long e){
    long long min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;
    if (e < min)
        min = e;
    return min;
}

long long max4(long long a, long long b, long long c, long long d, long long e){
    long long max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;
    if (e > max)
        max = e;
    return max;
}

void min_and_max(long long i, long long j, vector<long long> number, vector<char> operation, vector<vector<long long>> &M, vector<vector<long long>> &m){
    long long max = -10000000;
    long long min = 10000000;
    for (long long k = i; k < j; k++){
        long long a = eval(M[i][k], M[k+1][j], operation[k]);
        long long b = eval(M[i][k], m[k+1][j], operation[k]);
        long long c = eval(m[i][k], m[k+1][j], operation[k]);
        long long d = eval(m[i][k], M[k+1][j], operation[k]);
        min = min4(min, a, b, c, d);
        max = max4(max, a, b, c, d);
    }
    M[i][j] = max;
    m[i][j] = min;
}

long long paren(vector<vector<long long>> &M, vector<vector<long long>> &m, vector<long long> number, vector<char> operation, long long n){
    for(long long i =0; i < n; i++){
        M[i][i] = number[i];
        m[i][i] = number[i];
    }
    for(long long s = 1; s < n; s++)
        for (long long i = 0; i < n-s; i++){
            long long j = i + s;
            min_and_max(i, j, number, operation, M, m);
        }
    return M[0][n-1];
        
}

void printMatrixM(vector<vector<long long>> M, long long n){
    for(long long i =0; i < n; i++){
        for(long long j = 0 ; j< n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}
void printMatrixm(vector<vector<long long>> m, long long n){
    for(long long i =0; i < n; i++){
        for(long long j = 0 ; j< n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

int main() {
    string s;
    std::cin >> s;
    vector<long long> number;
    vector<char> operation;
    for(long long i = 0; i < s.size(); i+=2)
        number.push_back(s[i]-48);
    for(long long i = 1; i < s.size(); i+=2)
        operation.push_back(s[i]);
    vector<vector<long long>> M(number.size());
    vector<vector<long long>> m(number.size());
    for(long long i =0; i < number.size(); i++){
        M[i].resize(number.size());
        m[i].resize(number.size());
    }
    cout << paren(M, m, number, operation, number.size()) << endl;
//    prlong longMatrixM(M, number.size());
//    prlong longMatrixm(m, number.size());
    return 0;
}
