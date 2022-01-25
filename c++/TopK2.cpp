// 313. Super Ugly Number
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>

using namespace std;

class Solution1 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1);
        vector<int> nums(primes.size());
        vector<int> p(primes.size(), 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int min = INT_MAX;
            for(int j = 0; j < primes.size(); j++){
                nums[j] = dp[p[j]] * primes[j];
                min = std::min(min, nums[j]);
            }
            dp[i] = min;
            for(int j = 0; j < primes.size(); j++){
                if(min == nums[j])
                    p[j]++;
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> queue;
        long re = 1;
        for(int i = 1; i < n; i++){
            for(auto i: primes)
                queue.push(re*i);
            re = queue.top();
            queue.pop();
            while(!queue.empty() && re == queue.top())
                queue.pop();
        }

        return re;
    }
};

int main()
{
    Solution1 i;
    vector<int> vec{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,
                    89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
                    179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,
                    269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,
                    367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,
                    461,463,467,479,487,491,499,503,509,521,523,541};
    cout << i.nthSuperUglyNumber(1000000, vec) << endl;

    return 0;
}