//https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        return process(root, "");
    }
    string process(TreeNode* node, string str) {
        if(!node) return str;

        str.insert(0, 1, (char)('a' + node->val));
        string leftStr = process(node->left, str);
        string rightStr = process(node->right, str);
    
        if(!node->left) return rightStr;
        if(!node->right) return leftStr;

        return compareLexical(leftStr, rightStr);
    }

    string compareLexical(string left, string right) {
        int i = 0;
        int n = left.size() < right.size()? left.size(): right.size();

        while(i < n) {
            if(left[i] < right[i]) return left;
            if(left[i] > right[i++]) return right;
        }

        return left.size() < right.size()? left: right;
    }
};
