// 264. Ugly Number II
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<double> set;
        double re = 1;
        for(int i = 1; i < n; i++){
            set.insert(re*2);
            set.insert(re*3);
            set.insert(re*5);
            re = *set.begin();
            set.erase(re);
        }
        return re;
    }
};

class Solution1 {
public:
    int nthUglyNumber(int n) {
        priority_queue<double, vector<double>, greater<double>> queue;
        double re = 1;
        for(int i = 1; i < n; i++){
            queue.push(re*2);
            queue.push(re*3);
            queue.push(re*5);
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
    cout << i.nthUglyNumber(10) << endl;

    return 0;
}