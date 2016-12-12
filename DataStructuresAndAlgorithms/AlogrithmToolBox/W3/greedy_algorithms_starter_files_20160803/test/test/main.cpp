//
//  main.cpp
//  test
//
//  Created by Garrett Wang on 16/8/9.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>


using namespace std;
struct Segment {
    int start, end;
};


bool compareStruct(const Segment a, const Segment b){
    return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    sort(segments.begin(), segments.end(), compareStruct);
    for (size_t i = 0; i < segments.size(); ++i){
        int k = segments[i].end;
        while(k <= segments[i+1].end && k >= segments[i+1].start)
            i++;
        points.push_back(k);
    }
    //    for (size_t i = 0; i < segments.size(); ++i) {
    //        points.push_back(segments[i].start);
    //        points.push_back(segments[i].end);
    //    }
    return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
    cout << endl;
}


