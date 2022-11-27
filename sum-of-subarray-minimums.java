
//https://leetcode.com/problems/sum-of-subarray-minimums/description/
/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo 109 + 7.
*/

public Solution {
  
  //first solution
  public int sumSubarrayMins1(int[] arr) {
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
  
  //second solution, which is more efficient and fast 
  public static int sumSubarrayMins2(int[] arr) {
        int sum = 0;
        LinkedList<Integer> list = new LinkedList<>();
        int listPoint;

        for(int start = 0; start < arr.length; start++) {
            listPoint = 0;
            int end = arr.length - 1;

            //remove redundants from list
            int i = list.size() - 1;
            while(i >= 0 && list.get(i) < start) {
                list.remove(i);
                i--;
            }
            while(end >= start) {
                if(listPoint == list.size()) {
                    int min = arr[start];
                    int add_ind = start;
                    for(int j = start; j <= end; j++)
                        if(min > arr[j]) {
                            add_ind = j;
                            min = arr[j];
                        }
                    list.add(add_ind);
                }
                int index = list.get(listPoint);
                listPoint++;
                sum += (arr[index] * ((end - index) + 1));
                end = index - 1;
            }

            sum %= (int)(Math.pow(10,9) + 7);
        }

        return sum;
    }


}
