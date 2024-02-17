//question:      https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17
//my solution:   https://leetcode.com/problems/furthest-building-you-can-reach/solutions/4741489/beats-86-60-c-priority-queue-detailed-explanation/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        auto cmp = [](int a, int b) { return b < a; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int i = -1, n = heights.size();
        while(ladders && ++i < n-1) 
            if (heights[i] < heights[i + 1]) {
                pq.push(heights[i + 1] - heights[i]);
                ladders--;
            }
        if (i == n - 1) return i;
        int dif;
        while (++i < n - 1) {
            if (heights[i] >= heights[i + 1]) continue;
            dif = heights[i + 1] - heights[i];
            if (!pq.empty() && pq.top() < dif) {
                bricks -= pq.top();
                pq.pop();
                pq.push(dif);
            }
            else bricks -= dif;
            if (bricks < 0) return i;
        }
        return i;
    }
};
