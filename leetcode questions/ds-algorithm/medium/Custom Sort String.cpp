//question:       https://leetcode.com/problems/custom-sort-string/description/
//my solution:    https://leetcode.com/problems/custom-sort-string/solutions/4861280/beats-100-c-priority-queue/




class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> alphabet;
        
        for (int i = 0; i < order.size(); i++) alphabet[order[i]] = i;

        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Sort based on the second element
            };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        for (char ch : s) pq.push(make_pair(ch, alphabet[ch]));

        string result = "";
        while (!pq.empty()) {
            result += pq.top().first;
            pq.pop();
        }

        return result;
    }
};
