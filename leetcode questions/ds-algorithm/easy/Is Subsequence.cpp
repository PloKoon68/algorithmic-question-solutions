//https://leetcode.com/problems/is-subsequence/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.length() && !t.length()) return true;
        int j = 0;
        for(char ch: t) {
            if(ch == s[j]) j++;
            if(j == s.length()) return true;
        }   

        return false;
    }
};
