//question:       https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
//my solution:    https://leetcode.com/problems/letter-combinations-of-a-phone-number/solutions/4810428/beats-100-c/   



class Solution {
public:
    unordered_map<char, string> keyboard = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> combinations;

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        combine(digits, 0, "");
        return combinations;
    }
    void combine(string digits, int i, string combination) {
        if (i == digits.size()) {
            combinations.push_back(combination);
            return;
        }

        char digit = digits[i];
        for (char letter : keyboard[digit]) {
            combine(digits, i + 1, combination + letter);
        }
    }
};
