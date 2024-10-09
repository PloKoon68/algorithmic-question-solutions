//https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(char ch: s) {
            if(st.size()) {
                if(ch == 'B' && st.top() == 'A' || ch == 'D' && st.top() == 'C')
                    st.pop();
                else
                    st.push(ch);
            }
            else
                st.push(ch);
        }

        return st.size();
    }
};
