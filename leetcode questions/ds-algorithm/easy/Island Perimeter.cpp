//https://leetcode.com/problems/island-perimeter/description/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int per = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j]) {
                    per += 4;

                    if(i-1 >= 0 && grid[i-1][j]) per -= 2;
                    if(j-1 >= 0 && grid[i][j-1]) per -= 2;
                }
            }
        }

        return per;
    }
};
