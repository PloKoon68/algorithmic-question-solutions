//question:      https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25
/my solution:    https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/4923564/beats-87-28-c/



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> freq(nums.size()+1, 0);
        vector<int> result;
        for(int num: nums) {
            if(freq[num]) result.push_back(num);
            freq[num]++;
        }

        return result;
    }
};
