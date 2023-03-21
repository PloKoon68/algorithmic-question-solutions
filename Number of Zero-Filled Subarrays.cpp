//https://leetcode.com/problems/number-of-zero-filled-subarrays/



class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
          if(nums[i] == 0) {
            int j = i;
            long count = 0;
            while(j < nums.size()) {
              if(nums[j] == 0) {
                count++;
                j++;
              }
              else 
                break;
            }
            i = j;
            
            sum += count * (count + 1) / 2;
          }
        }
      return sum;
    }
};
