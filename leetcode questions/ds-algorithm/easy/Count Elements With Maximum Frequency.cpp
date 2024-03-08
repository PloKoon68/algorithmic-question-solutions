//question:       https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
//my solution:    https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/4844791/100-c/


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max = INT_MIN;
        for(int num: nums) {
            mp[num]++;
            if(mp[num] > max) max = mp[num];
        }
        int count = 0;

        for (auto i = mp.begin(); i != mp.end(); i++) 
            if(i->second == max) count+= max;
            
        return count;
    }
};
