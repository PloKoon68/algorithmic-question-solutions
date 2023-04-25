//easy
//https://leetcode.com/problems/shuffle-the-array/description/

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] arr = new int[n * 2];
        int i = 0, j=0;
        while(i < arr.length - 1) {
            arr[i++] = nums[j];
            arr[i++] = nums[n + j++];
            }
            return arr;
    }
}

