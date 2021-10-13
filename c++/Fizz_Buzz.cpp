//412.Fizz Buzz
/*Given an integer n, return a string array answer (1-indexed)*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str;
        for(int i = 1; i <= n; i++){
            if((i % 3) == 0 && (i % 5) == 0)
                str.push_back("FizzBuzz");
            else if((i % 3) == 0)
                str.push_back("Fizz");
            else if((i % 5) == 0)
                str.push_back("Buzz");
            else
                str.push_back(to_string(i));
        }

        return str;
    }
};

int main()
{
    int n;
    Solution item;

    cin >> n;
    vector<string> str = item.fizzBuzz(n);
    for(auto i : str)
        cout << i << " ";

    cout << endl;
    return 0;
}