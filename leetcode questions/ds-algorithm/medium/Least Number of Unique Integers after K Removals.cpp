//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16
//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/solutions/4739152/beats-81-71-c-priority-queue/


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counts;
        for (int i : arr) counts[i]++;
        
        auto cmp = [](int a, int b) { return b < a; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (const auto& pair : counts) pq.push(pair.second);

        while (!pq.empty()) {
            if (k < pq.top()) return pq.size();
            k -= pq.top();
            pq.pop();
        }
        return 0;
    }
};
