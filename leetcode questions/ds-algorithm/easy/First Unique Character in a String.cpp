//https://leetcode.com/problems/first-unique-character-in-a-string/


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        //store frequency of each character of s
        for (char ch : s) freq[ch - 'a']++;
        //first character with frequency = 1 is the answer
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        //no character with frequency = 1
        return -1;
    }
};
