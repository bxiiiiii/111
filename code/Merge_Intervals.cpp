#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> re;
    if (intervals.size() <= 0) {
      return re;
    }
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++) {
      int left = intervals[i][0];
      int right = intervals[i][1];
      if (re.size() == 0 || left > re.back()[1]) {
        re.push_back({left, right});
      } else {
        re.back()[1] = max(right, re.back()[1]);
      }
    }
    return re;
  }
};