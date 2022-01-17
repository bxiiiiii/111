// 373. Find K Pairs with Smallest Sums

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct node
    {
        int x, y;
        int i, j;

        bool operator < (const node& a) const{
            return x+y > a.x+a.y;
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> re;
        priority_queue<node> queue;
        for(int i = 0; i < nums1.size() && i < k; i++){
            node tt;
            tt.i = i;
            tt.j = 0;
            tt.x = nums1[i];
            tt.y = nums2[0];
            queue.push(tt);
        }

        while(k-- && !queue.empty()){
            node tmp = queue.top();
            queue.pop();
            re.push_back({tmp.x, tmp.y});
            if(tmp.j < nums2.size()-1){
                ++tmp.j;
                tmp.y = nums2[tmp.j];
                queue.push(tmp);
            }
        }
        return re;
    }
};

int main()
{
    Solution i;
    int k = 10;
    vector<int> nums1{-10,-4,0,0,6};
    vector<int> nums2{3,5,6,7,8,100};
    vector<vector<int>> ss = i.kSmallestPairs(nums1, nums2, k);
    for(int i = 0; i < ss.size(); i++){
        for(int j = 0; j < ss[i].size(); j++){
            cout << ss[i][j] << " " << endl;
        }
    }
    return 0;
}