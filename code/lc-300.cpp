#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size);
    for (int i = 0; i < size; i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};