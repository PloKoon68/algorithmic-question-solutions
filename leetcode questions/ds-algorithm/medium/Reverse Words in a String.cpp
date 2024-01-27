//https://leetcode.com/problems/reverse-words-in-a-string/description/


class Solution {
public:
    string reverseWords(string s) {
        string result = "";

        //for first word, do manually without any space
        int i = 0;
        string word = "";
        while(i < s.size() && s[i] == ' ')
            i++;
        while(i < s.size() && s[i] != ' ')
            word += s[i++];c

        while(i < s.size() && s[i] == ' ')
            i++;
        
        result = word;        
        if(i == s.size())
                return result;

        while(true) {
            string word = "";
            while(i < s.size() && s[i] != ' ')
                word += s[i++];

            while(i < s.size() && s[i] == ' ')
                i++;
            
            result = word + " " + result;

            if(i == s.size())
                return result;
        }
    }
};
