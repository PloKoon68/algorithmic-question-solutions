//question:        https://leetcode.com/problems/binary-subarrays-with-sum/description/
//my solution:     https://leetcode.com/problems/binary-subarrays-with-sum/solutions/4876564/beats-99-42-c-queue/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        queue<int> q;
        if (!nums.size()) return 0;


        int zeroCount = 0, i = 0, n = nums.size();
        int sum = 0;
        //if goal is 0
        if (!goal) {
            while (i < nums.size()) {
                while (i < nums.size() && !nums[i++]) zeroCount++;
                sum += (zeroCount * (zeroCount + 1)) / 2;
                zeroCount = 0;
            }
            return sum;
        }
        //first add goal times 0's coming before each 1's to the queue
        while (q.size() != goal) {
            while (i < nums.size() && !nums[i]) {
                zeroCount++;
                i++;
            }
            q.push(zeroCount+1);
           
            i++;
            zeroCount = 0;
        }  

        //then add number of left 0's + 1 times number of right 0's + 1 to sum each time and step through the next 1's
        while (i < n || (nums[n-1] && i == n)) {
            //son 1 de kal
            while (i < nums.size() && !nums[i]) {
                zeroCount++;
                i++;
            }
            zeroCount++;
            sum += q.front() * (zeroCount);
            
            q.push(zeroCount);
            q.pop();
            
            zeroCount = 0;
            i++;
        }

        return sum;
    }
};
