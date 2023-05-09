
//https://leetcode.com/problems/spiral-matrix/description/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralArr(matrix.size()*matrix[0].size());
        int start = 0, jEnd = matrix[0].size(), iEnd = matrix.size();
        int i, j, n = 0;
        while(start <= iEnd-1 && start <= jEnd-1) {
           i = start;
           j = start;
          
          while(j < jEnd && n < spiralArr.size()) 
            spiralArr[n++] = matrix[i][j++];
          j--;
          i++;
          
          while(i < iEnd && n < spiralArr.size()) 
            spiralArr[n++] = matrix[i++][j];
          i--;
          j--;
          
         while(j >= start && n < spiralArr.size()) 
            spiralArr[n++] = matrix[i][j--]; 
          j++;
          i--;
          
        while(i > start && n < spiralArr.size()) 
            spiralArr[n++] = matrix[i--][j]; 

          start++;
          jEnd--;
          iEnd--;
        }
      return spiralArr;
    }
};
