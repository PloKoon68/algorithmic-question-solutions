//question:    https://leetcode.com/problems/count-number-of-bad-pairs/description/
//solution explanation: https://leetcode.com/problems/count-number-of-bad-pairs/solutions/6412812/single-line-for-loop-on-c-by-ors_mehmet6-yjvo/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long sum = 0;
        unordered_map<int, int> diffs;
        int m = nums.size();
        for(int j = 0; j < m; j++) 
            sum += (j - diffs[nums[j] - j]++);

        return sum;
    }
};
