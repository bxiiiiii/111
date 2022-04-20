#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1){
            return 1;
        }
        int maxsublen = 0;
        int i = 0;
            for(int j = i+1; j < s.size();){
                bool ice = true;
                for(int k = i; k < j; k++){
                    if(s[j] == s[k]){
                        ice = false;
                        i = k+1;
                        break;
                    }
                }
                if(ice){
                    maxsublen = max(maxsublen, j-i+1);
                    ++j;
                }
            }
        
        return maxsublen;
    }
};