//476.Number Complement
/*The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.*/

class Solution {
public:
    int findComplement(int num) {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i) {
            if (num >= (1 << i)) {
                highbit = i;
            }
            else {
                break;
            }            
        }
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        return num ^ mask;
    }
};
