#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> re;
        if(security.size() <= time *2)
            return re;
        int ice;
        for(int i = time; i < security.size()-time && i > 0; i++){
            ice = 0;
            for(int left = i - time; left < i && left > 0; left++){
                cout << left << endl;
                if(security[left] < security[left+1])
                    goto out;}
            for(int right = i; right < i + time; right++){
                cout << right << endl;
                if(security[right] > security[right+1])
                    goto out;}
            cout << "***" << i << endl;
            re.push_back(i);
            out:;
        }
        return re;
    }
};

int main(){
    vector<int> o{1,1,1,1,1};
    Solution i;
    vector<int> j =i.goodDaysToRobBank(o, 0);
    for(auto x:j)
        cout << x << endl;

    return 0;
}