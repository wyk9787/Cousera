//
//  main.cpp
//  sorting
//
//  Created by Garrett Wang on 8/27/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }

    }
    swap(a[l], a[j]);
    return j;
}

//void partition3(vector<int> &a, int l, int r, int &m1, int &m2){
//    int x = a[l];
//    m1 = m2 = l;
//    for (int i = l + 1; i <= r; i++) {
//        if (a[i] <= x) {
//            m1++;
//            m2++;
//            swap(a[i], a[m1]);
//        }
//        
//    }
//    swap(a[l], a[m1]);
////    vector<int> b;
//    int b[100000];
//    int count = 0;
//    for(int i = l; i < m1; i++)
//        if(a[i] == a[m1]){
//            a.insert(a.begin()+m1, a[i]);
//            b[count] = i;
//            count++;
//        }
//    for(int i = 0; i < count; i++){
//        a.erase(a.begin()+b[i]);
//        for(int j = i; j < count; j++)
//            b[j]--;
//        m1--;
//    }
//    
//}

void partition3(vector<int> &a, int l, int r, int &m1, int &m2){
    int x = a[l];
    m1 = m2 = l;
    for(int i = l+1; i <= r; i++){
        if(a[i] <= x){
            m2++;
            swap(a[i], a[m2]);
        }
    }
    for(int i = l+1; i <= r; i++){
        if(a[i] < x){
            m1++;
            swap(a[i], a[m1]);
        }
    }
    swap(a[l], a[m1]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
//    int k =0;
    swap(a[l], a[k]);
//    int m = partition2(a, l, r);
    int m1, m2;
    partition3(a, l, r, m1, m2);
    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2+1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
