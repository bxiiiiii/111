// 747. Largest Number At Least Twice of Others

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int ret = -1;
        int num = nums.size();
        int max = nums[0], max_index = 0;
        for(int i = 1; i < num; i++)
            if(nums[i] > max){
                max = nums[i];
                max_index = i;
            }
        for(int i = 0; i < num; i++){
            if(i == max_index)
                continue;
            if(max < 2*nums[i]){
                max_index = -1;
                break;
            }
        }
        return max_index;
    }
};

int main()
{
    Solution i;
    vector<int> list{20,100,10,12,5,13};
    cout << i.dominantIndex(list) << endl;
    return 0;
}