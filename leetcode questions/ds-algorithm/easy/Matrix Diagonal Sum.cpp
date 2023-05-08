//https://leetcode.com/problems/matrix-diagonal-sum/description/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0;
        int sum = 0, size = mat.size();

        //with odd number element matrix, add the middle element manually
        sum += (size%2==1)? mat[size/2][size/2]: 0;
      
        while(i < size/2) {
          sum += mat[i][i];
          sum += mat[i][(size-1)-i];
          sum += mat[(size-1)-i][(size-1)-i];
          sum += mat[(size-1)-i][i];
          i++;
        }
      return sum;
    }
};
