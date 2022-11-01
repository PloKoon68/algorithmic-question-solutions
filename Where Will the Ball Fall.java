//leetcode question link
//https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
    public static int[] findBall(int[][] grid) {
        int[] keys = new int[grid[0].length];
        
        for(int column = 0; column < grid[0].length; column++) 
            keys[column] = dropBall(grid, column);
        
        
        return keys;
    }
    
    public static int dropBall(int[][] grid, int column) {
        int j = column;
        for(int row = 0; row < grid.length; row++) {
            //checl if -1
            if((grid[row][j] == 1 && ((j == grid[0].length - 1) || grid[row][j+1] == -1)) || 
                    (grid[row][j] == -1 && ((j == 0) || grid[row][j-1] == 1)))
                return -1;
            
            j = (grid[row][j]==1)? j + 1: j-1;
        }
        return j;
    }
  
}
