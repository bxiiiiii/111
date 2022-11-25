#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    vector<int> v1, v2;
    preHandle(version1, v1);
    preHandle(version2, v2);
    int lenmax = v1.size() > v2.size() ? v1.size() : v2.size();
    long sum1 = 0;
    long sum2 = 0;
    for (int i = 0; i < lenmax; i++) {
      if (i < v1.size()) {
        sum1 += v1[i];
      }
      if (i < v2.size()) {
        sum2 += v2[i];
      }
      if (sum1 > sum2) return 1;
      if (sum1 < sum2) return -1;
    }
    return 0;
  }
  void preHandle(string &s, vector<int> &vec) {
     string temp = "";
     for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            temp += s[i];
        } else if(s[i] == '.'){
            vec.push_back(atoi(temp.c_str()));
            temp = "";
        }
     }
     vec.push_back(atoi(temp.c_str()));
  }
};