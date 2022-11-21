#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    bool flag = false;
    string re = "";
    for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0 || flag; i--, j--) {
      int a = i >= 0 ? num1[i] - '0' : 0;
      int b = j >= 0 ? num2[j] - '0' : 0;
      int c = 0;
      if (flag) {
        c = a + b + 1;
      } else {
        c = a + b;
      }
      flag = false;
      if (c >= 10) {
        flag = true;
      }
      cout << c << endl;
      re.push_back('0' + c%10);
    }
    reverse(re.begin(), re.end());
    return re;
  }
};