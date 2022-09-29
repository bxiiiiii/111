#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> re;
  vector<string> generateParenthesis(int n) {
    vector<char> str;
    bt(str, n, 0, 0);
    return re;
  }
  void bt(vector<char> trace, int n, int left, int right) {
    if (trace.size() == n * 2) {
      string s(trace.begin(), trace.end());
      re.push_back(s);
    }
    if (left < n) {
      trace.push_back('(');
      bt(trace, n, left + 1, right);
      trace.pop_back();
    }
    if (right < left) {
      trace.push_back(')');
      bt(trace, n, left, right + 1);
      trace.pop_back();
    }
  }
};