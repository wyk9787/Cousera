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



int eval(int a, int b, char op) {
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

int min4(int a, int b, int c, int d, int e){
    int min = a;
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

int max4(int a, int b, int c, int d, int e){
    int max = a;
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

long long get_maximum_value(const string &exp) {
    //write your code here
   return 0;
}

void min_and_max(int i, int j, vector<int> number, vector<char> operation, int *M[0], int *m[0]){
    int max = 10000000;
    int min = -10000000;
    for (int k = i; k < j; k++){
        int a = eval(M[i][k], M[k+1][j], operation[k]);
        int b = eval(M[i][k], m[k+1][j], operation[k]);
        int c = eval(m[i][k], m[k+1][j], operation[k]);
        int d = eval(m[i][k], M[k+1][j], operation[k]);
        min = min4(min, a, b, c, d);
        max = max4(max, a, b, c, d);
    }
}

int main() {
    string s;
    std::cin >> s;
    vector<int> number;
    vector<char> operation;
    for(int i = 0; i < s.size(); i+=2)
        number.push_back(s[i]);
    for(int i = 1; i < s.size(); i+=2)
        operation.push_back(s[i]);
    int M[number.size()][number.size()];
    int m[number.size()][number.size()];
    std::cout << get_maximum_value(s) << '\n';
}
