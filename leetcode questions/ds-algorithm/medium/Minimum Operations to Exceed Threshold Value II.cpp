//question:   https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/
//my explanation: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/solutions/6418132/c-priority-queue-very-easy-by-ors_mehmet-n88j/


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        auto cmp = [](long long left, long long right) { return left > right; };
        priority_queue<long long, vector<long long>, decltype(cmp)> minHeap(cmp);

        for(int num: nums)
            minHeap.push(num);
       
        int count = 0;
        while(minHeap.top() < k) {
            long long combine = minHeap.top() * 2;
            minHeap.pop();
            combine = combine + minHeap.top();
            minHeap.pop();
            minHeap.push(combine);
            count++;
        }

        return count;
    }
};
