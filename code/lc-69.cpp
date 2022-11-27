#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int left = 1;
    int right = x;
    int re = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid <= x / mid) {
        left = mid + 1;
        re = mid;
      } else {
        right = mid - 1;
      }
    }
    return re;
  }
};