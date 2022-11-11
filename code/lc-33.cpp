#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 1) {
      if (target == nums[0]) {
        return 0;
      } else {
        return -1;
      }
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[left] < nums[mid]) {
        if (nums[mid] == target) {
          return mid;
        } else if (target > nums[mid - 1] || target < nums[left]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        if (nums[mid] == target) {
          return mid;
        } else if (target < nums[mid + 1] || target > nums[right]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }
    return -1;
  }
};