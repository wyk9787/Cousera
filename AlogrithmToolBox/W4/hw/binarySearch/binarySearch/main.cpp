//
//  main.cpp
//  binarySearch
//
//  Created by Garrett Wang on 16/8/25.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size();
    int middle = (left + right) / 2;
    while(left <= right){
        if(a[middle] == x)
            return middle;
        else if(a[middle] > x){
            right = middle -1;
            middle = (left + right) / 2;
        }
        else{
            left = middle + 1;
            middle = (left + right) / 2;
        }
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
//        std::cout << linear_search(a, b[i]) << ' ';
    }
    std::cout << std::endl;
}
