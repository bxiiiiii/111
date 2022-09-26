#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> re;
    for (int i = 0; i < nums.size(); i++) {
      re.push_back({});
      // for (int j = nums.size() - 1 - i; j < nums.size(); j++) {
      //   re[i].push_back(nums[j]);
      // }
      // for (int m = 0; m < nums.size() - 1 - i; m++) {
      //   re[i].push_back(nums[m]);
      // }
      for (int m = i; m < nums.size(); m++) {
        re[i].push_back(nums[m]);
      }
      for (int k = 0; k < i; k++) {
        re[i].push_back(nums[k]);
      }
    }
    return re;
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