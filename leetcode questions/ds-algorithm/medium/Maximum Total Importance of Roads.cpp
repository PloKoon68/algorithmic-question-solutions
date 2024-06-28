
//question:    https://leetcode.com/problems/maximum-total-importance-of-roads/description/
//my solution: https://leetcode.com/problems/maximum-total-importance-of-roads/


class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freqs(n, 0);
        for (vector<int> road : roads) {
            freqs[road[0]]++;
            freqs[road[1]]++;
        }

        priority_queue<long> pq;
        for (int freq : freqs) pq.push(freq);

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top() * n--;
            pq.pop();
        }

        return sum;
    }
};
