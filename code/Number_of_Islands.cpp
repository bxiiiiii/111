#include <iostream>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    count++;
                    bfs(grid, r, c);
                }
            }
        }
        return count;
    }

    bool inArea(std::vector<std::vector<char>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    int bfs(std::vector<std::vector<char>>& grid, int r, int c) {
        if(!inArea(grid, r, c)) {
            return 0;
        }

        if(grid[r][c] != '1') {
            return 0;
        } else {
            grid[r][c] = '2';
        }
            
        bfs(grid, r, c-1);
        bfs(grid, r, c+1);
        bfs(grid, r-1, c);
        bfs(grid, r+1, c);
    }
};