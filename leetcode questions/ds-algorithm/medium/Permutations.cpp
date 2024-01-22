 //https://leetcode.com/problems/permutations/description/


class Solution {
public:
    //result array
    vector<vector<int>> permutations;

    //swap function  
    void swap(vector<int>& arr, int ind1, int ind2) {
        int temp = arr[ind1];
        arr[ind1] = arr[ind2];
        arr[ind2] = temp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //start with level one, which is the initial version (input array nums)
        permutation(nums, 0);
        return permutations;
    }

    void permutation(vector<int> prev, int level) {
        //if it came to the lest level, which is for the last index, just add the array obtained so far to the resultant array and return
        if (level == prev.size() - 1) {
            permutations.push_back(prev);
            return;
        }

        
        int i = level;
        while (i < prev.size()) {
            //each step copy the previous levels array 
            vector<int> current = prev;
        
            //modify the previous arrays copy based on the current step
            swap(current, level, i);
            
            //go to the next level (right next elements index) with modified (current) array
            permutation(current, level+1);

            i++;
        }
    }

};
