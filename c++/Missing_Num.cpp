//268.Missing Number
/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/

#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < n; ++i) {
            sum1 += nums[i];
            sum2 += i;
        }

        return sum2 + n - sum1;
    }
};