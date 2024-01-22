//https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> recorded(nums.size()+1, 0);

        int missing, duplicated, sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            int current = nums[i];

            if(!recorded[current]) {
                recorded[current]++;
                sum += current;
            }
            else
                duplicated = current;
        }

        int n = nums.size();
        missing = n*(n+1)/2 - sum;
        
        vector<int> result = {duplicated, missing};
        return result;
    }
};
