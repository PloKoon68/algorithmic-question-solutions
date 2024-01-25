//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24


class Solution {
public:
    unordered_set<int> oddNums;
    int count = 0;
    int pseudoPalindromicPaths(TreeNode* root) {
        process(root);
        return count;
    }
    void process(TreeNode* currentNode) {
        //if node is null just return
        if (!currentNode)
            return;


        auto it = oddNums.find(currentNode->val);
        bool found = it != oddNums.end();
        // Element found, remove it from set
        if (found) 
            oddNums.erase(it);
        // Element not found, add it to the set
        else
            oddNums.insert(currentNode->val);


        //if at the final node of the path, check if it is palindrome and return
        if (!currentNode->left && !currentNode->right) {
            if (oddNums.size() <= 1)
                count++;
        }
        else {
            process(currentNode->left);
            process(currentNode->right);
        }

        //reverse the process to undo it while going back upward
        if (!found) {
            it = oddNums.find(currentNode->val);
            oddNums.erase(it);
        }
        else
            oddNums.insert(currentNode->val);
    }
};
