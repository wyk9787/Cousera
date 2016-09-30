//
//  main.cpp
//  test
//
//  Created by Garrett Wang on 16/8/9.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int l = 1;
    while(n > 2 * l){
        n -= l;
        summands.push_back(l);
        l += 1;
    }
    summands.push_back(n);
    
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
