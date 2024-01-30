//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

class Solution {
public:
    int i = 0;
    unordered_set<string> operands = {"+", "-", "*", "/"};

    int evalRPN(vector<string>& tokens) {
        i = tokens.size() - 1;
        return process(tokens);  
    }

    int process(vector<string>& tokens) {
        auto it = operands.find(tokens[i]);
        int right, left;
        string operand;
        //is operand
        if(it != operands.end()) {
            operand = tokens[i--];
            right = process(tokens);
        }
        else 
            return stoi(tokens[i--]);
        
        left = process(tokens);

        if (operand == "+") 
            return left + right;
        else if (operand == "-") 
            return left - right;
        else if (operand == "*") 
            return left * right;
        else if (operand == "/") 
            return left / right;

        return 0;  
    }
    
};
