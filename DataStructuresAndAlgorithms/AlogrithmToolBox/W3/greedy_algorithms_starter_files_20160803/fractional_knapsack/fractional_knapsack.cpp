//
//  main.cpp
//  test
//
//  Created by Garrett Wang on 16/8/9.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vector<double> sortWeight(vector<int> weights, vector<int> values, int n){
//    vector<double> sortedWeight(n);
//    for(int i = 0; i < n; i++)
//        sortedWeight[n] = values[n] / weights[n];
//    sort(sortedWeight.begin(), sortedWeight.end(), greater<int>());
//    return sortedWeight;
//}




double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
    double value = 0.0;
    //    vector<double> sortedWeight(n);
    //    sortedWeight = sortWeight(weights, values, n);
    for(int i = 0; i < n; i++){
        if(capacity == 0)
            return value;
        double maxamount = 0;
        int maxi = 0;
        for(int j = 0; j < n; j++)
            if(weights[j] != 0)
                if(maxamount < (double)values[j] / weights[j]){
                    maxamount = (double)values[j] / weights[j];
                    maxi = j;
                }
        double a = min((double)weights[maxi], (double)capacity);
        value += a * maxamount;
        weights[maxi] -= a;
        capacity -= a;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }
    
    double optimal_value = get_optimal_value(capacity, weights, values, n);
    
    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
