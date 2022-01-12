// 334. Increasing Triplet Subsequence
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0];
        int second = INT_MAX;
        bool ice = false;
        if(nums.size() < 3)
            return ice;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > second){
                ice = true;
                break;
            } else if(nums[i] <= first){
                first = nums[i];
            }else{
                second = nums[i];
            }
        }
        return ice;
    }
};

int main()
{
    Solution i;
    vector<int> list{20,100,10,12,5,13};
    cout << i.increasingTriplet(list) << endl;
    return 0;
}