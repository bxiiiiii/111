#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> sta;
    for (auto i : s) {
      if (i == '(' || i == '{' || i == '[') {
        sta.push(i);
      } else if (i == ')') {
        if (sta.empty()) {
          return false;
        }
        if (sta.top() == '(') {
          sta.pop();
        } else {
          return false;
        }
      } else if (i == '}') {
        if (sta.empty()) {
          return false;
        }
        if (sta.top() == '{') {
          sta.pop();
        } else {
          return false;
        }
      } else if (i == ']') {
        if (sta.empty()) {
          return false;
        }
        if (sta.top() == '[') {
          sta.pop();
        } else {
          return false;
        }
      }
    }
    if (sta.empty()) {
      return true;
    }
    return false;
  }
};