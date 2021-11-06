//367.Vaild Perfect Square
/*Given a positive integer num, write a function which returns True if num is a perfect square else False.*/
//Do not use any built-in library function such as sqrt.

#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        int ls = 0;
        int rs = num;
        while(ls + 1 != rs) {
            int mid = (rs - ls) / 2 + ls;
            int tem = num / mid;
            if(mid == tem && num % tem == 0)
                return 0;
            if(tem < mid)
                rs = mid;
            else
                ls = mid;
        }
        if(ls == 0)
            return true;

        return false;
    } 
};