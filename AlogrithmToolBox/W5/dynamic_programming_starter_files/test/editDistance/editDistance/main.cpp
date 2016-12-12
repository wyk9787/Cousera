//
//  main.cpp
//  editDistance
//
//  Created by Garrett Wang on 10/17/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min3 (int a, int b, int c){
    if (a < b)
        if(a < c)
            return a;
        else
            return c;
    else
        if(b < c)
            return b;
        else
            return c;
}

int edit_distance(const string &str1, const string &str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> d(n+1);
    for(int i = 0; i <= n; i++)
        d[i].resize(m+1);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++){
            d[i][0] = i;
            d[0][j] = j;
        }
    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++){
            int insertion = d[i][j-1] + 1;
            int deletion = d[i-1][j] + 1;
            int match = d[i-1][j-1];
            int mismatch = d[i-1][j-1] + 1;
            if (str1[i-1] == str2[j-1])
                d[i][j] = min3(insertion, deletion, match);
            else
                d[i][j] = min3(insertion, deletion, mismatch);
        }
    }
    return d[n][m];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}
