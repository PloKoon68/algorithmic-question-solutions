//https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));

        
        int least = INT_MAX;
        for (int top = 0; top < matrix.size(); top++) {
            recursiveSum(matrix, dp, 0, top);
            if(dp[0][top] < least)
                least = dp[0][top];
        }
        return least;
    }

    void recursiveSum(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {

        //at the bottom, just return that element
        if (i == matrix.size() - 1) {
            dp[i][j] = matrix[i][j];
            return;
        }
       

        int least = INT_MAX;
        for (int next = -1; next <= 1; next++) {
            int childJ = j + next;

            //check if child is in range
            if (childJ >= 0 && childJ < matrix.size()) {
                //if the child isn't visited before, visit it
                if (dp[i + 1][childJ] == INT_MAX)
                    recursiveSum(matrix, dp, i + 1, childJ);
            }
            else
                continue;

            if (dp[i + 1][childJ] < least)
                least = dp[i + 1][childJ];
            
        }
        dp[i][j] = matrix[i][j] + least;
        
    }
};
