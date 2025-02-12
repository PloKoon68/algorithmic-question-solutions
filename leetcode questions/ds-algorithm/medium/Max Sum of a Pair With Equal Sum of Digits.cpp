//question:   https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
//my explanation: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/solutions/6413114/c-single-travers-easy-and-fast-by-ors_me-xk8p/


class Solution {
public:
    int digitSummation(int num) {
        int digitSum = 0;
        while(num) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxNums;

        int maxSum = 0;
        for(int num: nums) {
            int digitSum = digitSummation(num);
            if(!maxNums[digitSum]) maxNums[digitSum] = num;
            else {
                if(maxNums[digitSum] + num > maxSum) maxSum = maxNums[digitSum] + num;
                if(num > maxNums[digitSum]) maxNums[digitSum] = num;
            }
        }

        return maxSum? maxSum: -1;
    }
};


