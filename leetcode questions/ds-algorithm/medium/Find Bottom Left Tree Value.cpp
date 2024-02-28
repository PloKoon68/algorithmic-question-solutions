//question:     https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28
//my solution:  https://leetcode.com/problems/find-bottom-left-tree-value/solutions/4793303/c-easy-solution-beats-79-runtime-100-memory/
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
    int maxLevel, val; 
    int findBottomLeftValue(TreeNode* root) {
        maxLevel = 0, val = root->val;
        traverse(root, 0);
        return val;
    }
    void traverse(TreeNode* node, int level) {
        if(node->left) traverse(node->left, level+1);
        if(node->right) traverse(node->right, level+1);
        if(level > maxLevel){ maxLevel = level; val = node->val;}
    }
};
