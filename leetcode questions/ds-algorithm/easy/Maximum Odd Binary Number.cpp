
//quesiton:        https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01
//my solution:     https://leetcode.com/problems/maximum-odd-binary-number/solutions/4807374/beats-100-c-easy-solutioon/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string result = "";
        for (char digit : s) if (digit == '1') result += '1';
        result.pop_back();
        int n = s.size() - result.length(), i = 1;
        while (i++ < n) result += '0';
        result += '1';
        return result;
    }
};
