//question:      https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24
//my solution:   https://leetcode.com/problems/find-the-duplicate-number/solutions/4919007/beats-97-86-c/?envType=daily-question&envId=2024-03-24

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq(nums.size(), 0);

        for(int num: nums) {
            if(freq[num]) return num;
            freq[num]++;
        }
        return -1;
    }
};
