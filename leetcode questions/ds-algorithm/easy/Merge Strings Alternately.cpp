//https://leetcode.com/problems/merge-strings-alternately/description/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len, num = 0;
        if(word1.length() > word2.length()) 
            len = word2.length();
        else {
            len = word1.length();
            num++;
        }

        int i;
        string s = "";
        for(i = 0; i < len; i++) {
            s += word1[i];
            s += word2[i];
        }        
        if(num)
            while(i < word2.length()) {
                s += word2[i];
                i++;
            }
        else
            while(i < word1.length()) {
                s += word1[i];
                i++;
            }
        return s;
    }
};
