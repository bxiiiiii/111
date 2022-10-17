#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--) {
            for(int j = nums.size() - 1; j > i; j--) {
                if(nums[j] > nums[i]){
                    swap(nums[j], nums[i]);
                    reverse(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};