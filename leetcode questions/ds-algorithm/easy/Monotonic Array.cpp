//https://leetcode.com/problems/monotonic-array/description/?envType=daily-question&envId=2023-09-29

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1)
            return true;


        int i = 1;
        while(i < nums.size() && nums[i] == nums[i-1]) 
            i++;
        
        if(i == nums.size())
            return true;


        //inc
        if(nums[i] > nums[i - 1]) 
            while(i < nums.size()) {
                if(nums[i] < nums[i-1])
                    return false;
                i++;
            }
        else 
            while(i < nums.size()) {
                if(nums[i] > nums[i-1])
                    return false;
                i++;
            }
        
        return true;

    }
};



