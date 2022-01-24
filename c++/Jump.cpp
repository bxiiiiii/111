// 55. Jump Game
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > sum) return false;
            sum = max(sum, i+nums[i]);
        }
        return true;
    }
};

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        dp[0] = true;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] + j >= i){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

int main()
{
    Solution i;
    vector<int> nums1{2,3,1,1,4};
    cout << i.canJump(nums1) << endl;

    return 0;
}