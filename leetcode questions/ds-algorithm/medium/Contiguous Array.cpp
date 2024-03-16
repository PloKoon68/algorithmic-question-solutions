//https://leetcode.com/problems/contiguous-array/description/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0, maxDist = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;

            if (mp.find(sum) != mp.end()) {
                int distance = i - mp[sum];
                if (distance > maxDist) maxDist = distance;
            }
            else mp[sum] = i;
        }

        return maxDist;
    }
};
