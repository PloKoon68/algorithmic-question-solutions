//https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28

class Solution {
public:
    int max = 0;
    int sum = 0;
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> stepped(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (!stepped[i][j] && grid[i][j]) {
                    sum = 0;
                    fishCountInLake(grid, stepped, i, j, n, m);
                    if (sum > max) max = sum;
                }
        }

        return max;
    }
    void fishCountInLake(vector<vector<int>>& grid, vector<vector<int>>& stepped, int i, int j, int& n, int& m) {
        sum += grid[i][j];
        stepped[i][j]++;
        if (i + 1 < n && !stepped[i + 1][j] && grid[i + 1][j])
            fishCountInLake(grid, stepped, i + 1, j, n, m);
        if (i - 1 >= 0 && !stepped[i - 1][j] && grid[i - 1][j])
            fishCountInLake(grid, stepped, i - 1, j, n, m);
        if (j + 1 < m && !stepped[i][j + 1] && grid[i][j + 1])
            fishCountInLake(grid, stepped, i, j + 1, n, m);
        if (j - 1 >= 0 && !stepped[i][j - 1] && grid[i][j - 1])
            fishCountInLake(grid, stepped, i, j - 1, n, m);
    }
};
