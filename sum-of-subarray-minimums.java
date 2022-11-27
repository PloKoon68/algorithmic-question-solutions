
//https://leetcode.com/problems/sum-of-subarray-minimums/description/
/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo 109 + 7.
*/

public Solution {
  
  //first solution
  public static int sumSubarrayMins1(int[] arr) {
        int sum = 0;
        for(int len = 1; len <= arr.length; len++) {
            for(int start = 0; start <= arr.length - len; start++) {
                int min = arr[start];
                for(int i = start; i < start + len; i++) {
                    if(arr[i] < min)
                        min = arr[i];
                }
                 sum += min;
            }
        }
        return sum % (int)(Math.pow(10,9) + 7);
    }



}
