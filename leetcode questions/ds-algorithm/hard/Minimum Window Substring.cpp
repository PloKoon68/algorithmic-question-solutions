//question:     https://leetcode.com/problems/minimum-window-substring/
//my solution:  https://leetcode.com/problems/minimum-window-substring/solutions/4675514/beats-98-54-c/


class Solution {
public:
    int getIndex(char ch) {
        return (ch >= 'a') ? (ch - 'a') : ch - 'A' + 26;
    }
    string minWindow(string s, string t) {
        int tIndex[52] = { 0 };
        int count = t.size(); 
        for (char ch: t) tIndex[getIndex(ch)]++;
        int minLen = INT_MAX, start = 0;
        int sIndex[52] = { 0 };
        queue<int> q;
        for (int i = 0; i < s.length(); i++) {
            int ind = getIndex(s[i]);
            if (tIndex[ind]) {
                sIndex[ind]++;
                q.push(i);
                if(sIndex[ind] <= tIndex[ind]) count--;
            }
            if (!count) {
                int front = getIndex(s[q.front()]);
                while (sIndex[front] > tIndex[front]) {
                    --sIndex[front];
                    q.pop();
                    front = getIndex(s[q.front()]);
                }
                int len = i - q.front() + 1;
                if (minLen > len) {
                    minLen = len;
                    start = q.front();
                }
                --sIndex[front];
                q.pop();
                count++;
            }
        }
        if (minLen == INT_MAX) minLen = 0;
        return s.substr(start, minLen);
    }
};
