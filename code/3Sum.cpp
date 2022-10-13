#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> re;
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
      return re;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right && left < nums.size() && right > 0) {
        if (nums[i] + nums[left] + nums[right] == 0) {
          re.push_back({nums[left], nums[i], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) left++;
          while (left < right && nums[right] == nums[right - 1]) right--;
          left++;
          right--;
        } else if (nums[i] + nums[left] + nums[right] > 0) {
          right--;
        } else {
          left++;
        }
      }
    }
    return re;
  }
};

int main() {
  Solution s;
  vector<int> vec = {-1, 0, 1, -1};
  s.threeSum(vec);
  for (auto i : s.re) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}