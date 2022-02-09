// 1508. Range Sum of Sorted Subarray Sums
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>

class Solution {
public:
    static constexpr int MODULO = 1000000007;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefixSums = vector<int>(n + 1);
        prefixSums[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        vector<int> prefixPrefixSums = vector<int>(n + 1);
        prefixPrefixSums[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixPrefixSums[i + 1] = prefixPrefixSums[i] + prefixSums[i + 1];
        }
        return (getSum(prefixSums, prefixPrefixSums, n, right) - getSum(prefixSums, prefixPrefixSums, n, left - 1)) % MODULO;
    }

    int getSum(vector<int>& prefixSums, vector<int>& prefixPrefixSums, int n, int k) {
        int num = getKth(prefixSums, n, k);
        int sum = 0;
        int count = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (j <= n && prefixSums[j] - prefixSums[i] < num) {
                j++;
            }
            j--;
            sum += prefixPrefixSums[j] - prefixPrefixSums[i] - prefixSums[i] * (j - i);
            sum %= MODULO;
            count += j - i;
        }
        sum += num * (k - count);
        return sum;
    }

    int getKth(vector<int>& prefixSums, int n, int k) {
        int low = 0, high = prefixSums[n];
        while (low < high) {
            int mid = (high - low) / 2 + low;
            int count = getCount(prefixSums, n, mid);
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int getCount(vector<int>& prefixSums, int n, int x) {
        int count = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (j <= n && prefixSums[j] - prefixSums[i] <= x) {
                j++;
            }
            j--;
            count += j - i;
        }
        return count;
    }
};
