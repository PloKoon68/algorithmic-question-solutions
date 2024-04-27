//https://leetcode.com/problems/minimum-falling-path-sum-ii/?envType=daily-question&envId=2024-04-26


class Solution {
public:
    int n;
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 0; j < n; j++) process(grid, dp, 0, j);
        int min = dp[0][0];
        for(int j = 1; j < n; j++) if(min > dp[0][j]) min = dp[0][j];

        return min;

    }

    void process(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int jPrev) {
        if(i == n-1) {
            dp[i][jPrev] = grid[i][jPrev];
            return;
        }

        int sum = 0, in = i+1, min = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(!dp[in][j]) process(grid, dp, in, j);
            if(j != jPrev && min > dp[in][j]) min = dp[in][j];
        }
        dp[i][jPrev] = grid[i][jPrev] + min;
    }
};
