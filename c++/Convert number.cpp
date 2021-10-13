//273.Integer to English Words
/*Convert a non-negative integer num to its English words representation.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
        vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if(!num)
            return "Zero";
            
        string str = split(num);
        str.pop_back();

        return str;
        
    }
    string split(int num)
    {
        string str = "";
        int billion = num / 1000000000;
        num %= 1000000000;
        int million = num / 1000000;
        num %= 1000000;
        int thousand = num / 1000;
        num %= 1000;
    
        if(billion)
            str += split(billion) + "Billion ";
        if(million)
            str += split(million) + "Million ";
        if(thousand)
            str += split(thousand) + "Thousand ";

        str += f(num);

        return str;
    }

    string f(int n)
    {
        string str = "";

        int hundred = n/100;
        if(hundred)
            str += singles[hundred] + " Hundred ";

        n %= 100;
        if(n < 20 && n >= 10){
            str += teens[n%10] + " ";
            return str;
        }else if(n >= 20)
            str += tens[n/10] + " ";
        n %= 10;
        if(!n)
            return str;
        
        str += singles[n%10] + " ";

        return str;
    }
};

int main()
{
    Solution item;
    int num;
    cin >> num;
    item.numberToWords(num);

    return 0;
}