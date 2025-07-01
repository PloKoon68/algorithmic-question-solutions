// https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01


class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0, len = word.size(), possibilities = 1;
        char prevChar = word[0];
        for(int i = 1; i < len; i++) {
            if(word[i] == prevChar) count++;
            else {
                possibilities += count;
                count = 0;
                prevChar = word[i];
            }
        }
        possibilities += count;

        return possibilities;
    }
};
