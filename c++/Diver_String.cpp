// 1405. Longest Happy String

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int>> queue;
        if(a) queue.push({a, 0});
        if(b) queue.push({b, 1});
        if(c) queue.push({c, 2});

        string re;
        while(!queue.empty()){
            pair<int, int> max = queue.top();
            queue.pop();
            if(re.size() >= 2 && max.second + 'a' == re[re.size()-1]
                                && max.second + 'a' == re[re.size()-2]){
                if(queue.empty())
                    break;
                pair<int, int> mmax = queue.top();
                queue.pop();
                re += ('a' + mmax.second);
                mmax.first -= 1;
                if(mmax.first)
                    queue.push(mmax);
                queue.push(max);
            }  else {
                re += ('a' + max.second);
                max.first -= 1;
                if(max.first)
                    queue.push(max);
            }
        }
        return re;
    }
};