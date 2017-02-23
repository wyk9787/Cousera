#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

int PatternCount(string text, string pattern) {
  int count = 0;
  for (int i = 0; i <= text.length() - pattern.length(); i++) {
    if (text.substr(i, pattern.length()) == pattern) {
      count++;
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  string text, pattern;
  cin >> text >> pattern;
  cout << PatternCount(text, pattern) << endl;
  return 0;
}
