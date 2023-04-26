//https://leetcode.com/problems/valid-parentheses/description/




class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false;
         stack<int> st;
         for(char c: s) {
            if(c == ')' || c== '}' || c == ']')
                if(!st.size()) return false;
                switch(c) {
                    case ')':
                        if(st.top() != '(') return false;
                        st.pop();
                        continue;
                    case '}':
                        if(st.top() != '{') return false;
                        st.pop();
                        continue;
                    case ']':
                        if(st.top() != '[') return false;
                        st.pop();
                        continue;
                }
            st.push(c);
        }
        return (!st.size());
    }    
};
