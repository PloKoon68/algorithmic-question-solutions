//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> spiral(n, vector<int>(n));
      int start = 0;
        int i, j, end = n, cur = 1;
        while(start < n/2) {
           i = start;
           j = start;
          
          while(j < end && cur <= n*n) 
            spiral[i][j++] = cur++;
          j--;
          i++;
          
          while(i < end && cur <= n*n) 
            spiral[i++][j] = cur++;
          i--;
          j--;
          
         while(j >= start && cur <= n*n) 
            spiral[i][j--] = cur++; 
          j++;
          i--;
          
        while(i > start && cur <= n*n) 
            spiral[i--][j] = cur++; 

          start++;
          end--;
        }

      if(n % 2 == 1)
        spiral[n/2][n/2] = n*n;
      return spiral;
      
    }
};
