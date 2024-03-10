//https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> added;
        for(int num: nums1) added.insert(num);
        vector<int> result;
        for(int num: nums2) 
            if(added.contains(num)) {
                result.push_back(num);
                added.erase(num);
            }
        return result;
    }
};
