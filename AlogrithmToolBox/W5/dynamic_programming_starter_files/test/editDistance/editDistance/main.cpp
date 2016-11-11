//
//  main.cpp
//  editDistance
//
//  Created by Garrett Wang on 10/17/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#include <iostream>
#include <string>

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
    int m = str1.length();
    int n = str2.length();
    int d[m][n];

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++){
            d[i][0] = i;
            d[0][j] = j;
        }
    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= m; i++){
            int insertion = d[i][j-1] + 1;
            int deletion = d[i-1][j] + 1;
            int match = d[i-1][j-1];
            int mismatch = d[i-1][j-1] + 1;
            if (str1[i] == str2[j])
                d[i][j] = min3(insertion, deletion, match);
            else
                d[i][j] = min3(insertion, deletion, mismatch);
        }
    }
    return d[m][n];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}
