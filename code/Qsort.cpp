#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    sort(nums, 0, nums.size() - 1);
    return nums;
  }

  int getmid(vector<int>& nums, int left, int right) {
    int mid = nums[left];
    while (left < right) {
      while (nums[right] >= mid && left < right) {
        right--;
      }
      nums[left] = nums[right];
      while (nums[left] <= mid && left < right) {
        left++;
      }
      nums[right] = nums[left];
    }
    nums[left] = mid;
    return left;
  }

  void sort(vector<int>& nums, int left, int right) {
    if (left < right) {
      int mid = getmid(nums, left, right);
      sort(nums, 0, mid - 1);
      sort(nums, mid + 1, right);
    }
  }
};

int main(){
    vector<int> nums{5,4,3,8,1};
    Solution i;
    vector<int> re= i.sortArray(nums);
    for(auto i : re){
        cout << i << endl;
    }
    return 0;
}