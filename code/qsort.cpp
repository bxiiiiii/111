#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    qsort(nums, 0, nums.size() - 1);
    return nums;
  }

  int getmid(vector<int>& nums, int left, int right) {
    int mid = nums[left];
    while (left < right) {
      while (left < right && nums[right] >= mid) right--;
      nums[left] = nums[right];
      while (left < right && nums[left] <= mid) left++;
      nums[right] = nums[left];
      
    }
    nums[left] = mid;
    return left;
  }

  void qsort(vector<int>& nums, int left, int right) {
    if (left < right) {
      int mid = getmid(nums, left, right);
      qsort(nums, left, mid - 1);
      qsort(nums, mid + 1, right);
    }
  }
};

int main() {
  Solution s;
  vector<int> vec{5, 2, 3, 1};
  s.sortArray(vec);

  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
}