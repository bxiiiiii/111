//229.Majority Element 2
/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> cnt;

        for (auto & v : nums) {
            cnt[v]++;
        }
        for (auto & v : cnt) {
            if (v.second > n / 3) {
                ans.push_back(v.first);
            }
        }

        return ans;
    }
};

class Moore_vote{
public:
    vector<int> majorityElement(vector<int>& nums){
        vector<int> ans;
        int elem1 = 0;
        int elem2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for(auto& i : nums){
            if(vote1 > 0 && i == elem1){
                vote1++;
            }else if(vote2 > 0 && i == elem2)
                vote2++;
            else if(vote1 == 0){
                elem1 = i;
                vote1++;
            }else if(vote2 == 0){
                elem2 = i;
                vote2++;
            }else{
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for(auto& i : nums){
            if(vote1 > 0 && i == elem1)
                cnt1++;
            if(vote2 > 0 && i == elem2)
                cnt2++;
        }

        if(vote1 > 0 && cnt1 > nums.size() / 3)
            ans.push_back(elem1);
        if(vote2 > 0 && cnt2 > nums.size() / 3)
            ans.push_back(elem2);

        return ans;
    }
};