//
//  main.cpp
//  majorityElection
//
//  Created by Garrett Wang on 16/8/25.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

int b[1000000000+5];
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
//    if(m == n && m != -1)
//        return 1;
    return -1;
}

int get_majority_element(vector<int> &a, int *b){
    for(int i = 0; i < a.size(); i++)
        b[a[i]] ++;
    for(int i = 0; i < 100000000+5; i++)
        if(b[i] > a.size()/2)
            return 1;
    return 0;
}

int main() {
    int n;
    std::cin >> n;

    vector<int> a(n);
//    for(int i = 0; i < b.size(); i++)
//        b[i] = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
//    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
    std::cout << get_majority_element(a, b) << std::endl;
}
