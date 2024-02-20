//question:       https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
//my solution:    https://leetcode.com/problems/missing-number/solutions/4759417/beats-100-c-single-traverse/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) sum += num;
        return n * (n + 1) / 2 - sum;
    }
};
