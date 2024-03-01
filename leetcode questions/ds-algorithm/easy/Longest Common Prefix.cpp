//question        https://leetcode.com/problems/longest-common-prefix/description/
//my solution:    https://leetcode.com/problems/longest-common-prefix/solutions/4807449/beats-100-c/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs[0].size()) return "";
        if(strs.size() == 1) return strs[0];
        int i = 0;
        string result = "";
        while (true) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) 
                if (i >= strs[j].size() || strs[j][i] != ch) return result;
            result += ch;
            i++;
        }
        return result;
    }
};
