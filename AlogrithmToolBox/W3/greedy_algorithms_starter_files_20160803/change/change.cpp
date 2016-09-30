//
//  main.cpp
//  test
//
//  Created by Garrett Wang on 16/8/9.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int get_change(int m) {
    int n = 0;
    int i = 0;
    int a[3] = {10, 5, 1};
    while(m > 0){
        int k = min(a[i], m);
        while(k < a[i] && i != 2){
            i++;
            k = min(a[i], m);
        }
        m -= min(a[i], m);
        n++;
    }
    return n;
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
