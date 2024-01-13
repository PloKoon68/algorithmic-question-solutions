//https://leetcode.com/problems/majority-element/

class Solution {
public:
    
int majorityElement(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];

    int count = 1, d = nums[0], i = 1;
    int h = nums.size() / 2;

    while (i < nums.size() && count <= h) {
        if (nums[i] == d)
            count++;
        else {
            if (count > 0) 
                count--;
            else {
                d = nums[i];
                count++;
            }
        }
        i++;
    }
    return d;
}
};
