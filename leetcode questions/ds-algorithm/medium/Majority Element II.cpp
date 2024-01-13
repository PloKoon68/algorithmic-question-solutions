//https://leetcode.com/problems/majority-element-ii/description/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    if (nums.size() == 1)
        return nums;

    int i = 0;
    int h = nums.size() / 3;

    unordered_set<int> alreadyChecked = {};
    unordered_map<int, int> track;



    while (i < nums.size()) {
        
        if (alreadyChecked.count(nums[i]) > 0) {
            i++;
            continue;
        }
        else {
            track[nums[i]]++;
            if (track[nums[i]] > h)
                alreadyChecked.insert(nums[i]);
        }
        
        i++;
    }

    vector<int> result(alreadyChecked.begin(), alreadyChecked.end());

 
    return result;
}
};
