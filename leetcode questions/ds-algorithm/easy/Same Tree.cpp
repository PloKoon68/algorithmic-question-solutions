//question:       https://leetcode.com/problems/same-tree/description/
//my solution:    https://leetcode.com/problems/same-tree/solutions/4793357/c-beats-100-2-lines/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && !q || !p && q) return false;
        return !p && !q ||(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
