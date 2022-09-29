#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> re;
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> trace;
    backtrace(nums, trace);
    return re;
  }
  void backtrace(vector<int>& nums, vector<int>& trace) {
    if (trace.size() == nums.size()) {
      re.push_back(trace);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (count(trace.begin(), trace.end(), nums[i])) {
        continue;
      }
      trace.push_back(nums[i]);
      backtrace(nums, trace);
      trace.pop_back();
    }
  }
};
int main() {
  Solution s;
  vector<int> vec{1, 2, 3};
  auto re = s.permute(vec);
  for (auto j : re) {
    for (auto i : j) {
      cout << i;
    }
    cout << endl;
  }
  return 0;
}