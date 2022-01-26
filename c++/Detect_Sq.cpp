// 2013.Detect Squares

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class DetectSquares {
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        map[y][x]++;
    }
    
    int count(vector<int> point) {
        int re = 0;
        int x = point[0], y = point[1];
        if(!map.count(y))
            return 0;
        unordered_map<int , int> yCnt = map[y];
        for(auto &[col, colCnt] : map){
            if(col != y){
                int len = col - y;
                re += (colCnt.count(x) ? colCnt[x] : 0) 
                        * (yCnt.count(x + len) ? yCnt[x + len] : 0)
                        * (colCnt.count(x + len) ? colCnt[x + len] : 0);
                re += (colCnt.count(x) ? colCnt[x] : 0) 
                        * (yCnt.count(x - len) ? yCnt[x - len] : 0)
                        * (colCnt.count(x - len) ? colCnt[x - len] : 0);
            }
        }
        return re;
    }
private:
    unordered_map<int, unordered_map<int, int>> map;
};