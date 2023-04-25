
//https://leetcode.com/problems/removing-stars-from-a-string/description/




class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        for(int i=0;i<s.size();i++){
            char cur = s[i];
            if(cur == '*'){
                stk.pop();
            }else{
                stk.push(cur);
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//better solution is:
class Solution {
public:
    string removeStars(string s) {
        int i=0,j=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='*'){
                j--;
            }else{
                s[j++] = s[i];
            }
        }
        return s.substr(0,j);
    }
};
