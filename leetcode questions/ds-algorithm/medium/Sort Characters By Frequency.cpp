//https://leetcode.com/problems/sort-characters-by-frequency/?envType=daily-question&envId=2024-02-07

class Solution {
public:
    string frequencySort(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {return a.second < b.second;};
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        int freq[62] = {0};
        for (char ch : s) {
            if (ch >= 'a') freq[ch - 'a']++;
            else if (ch >= 'A') freq[ch - 'A' + 26]++;
            else freq[ch - '0' + 52]++;
        }
        for (int i = 0; i < 26; i++)
            if (freq[i]) pq.push(make_pair((char)'a' + i, freq[i]));
        //for uppercase chars
        for (int i = 26; i < 52; i++)
            if (freq[i]) pq.push(make_pair((char)'A' + i - 26, freq[i]));
        for (int i = 52; i < 62; i++)
            if (freq[i]) pq.push(make_pair((char)'0' + i - 52, freq[i]));

        string result = "";
        while (!pq.empty()) {
            result.append(pq.top().second, pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};
