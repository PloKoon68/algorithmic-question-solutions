//question:     https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28
//my solution:  https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/solutions/4936582/beats-93-c-map/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(nums.size() == 1) return 1;
        if(!nums.size()) return 0;

        int left = 0, right = 0, n = nums.size(), max = 0;
        unordered_map<int, int> freq;
        while(right < n) {
            while(right < n && freq[nums[right]] < k) freq[nums[right++]]++;
            if(max < right - left) max = right - left;

            if(right < n) {
                int dec = nums[right];
                while(left < right && nums[left] != dec) freq[nums[left++]]--;
                freq[nums[left++]]--;
            }
        }

        return max;
    }
};
