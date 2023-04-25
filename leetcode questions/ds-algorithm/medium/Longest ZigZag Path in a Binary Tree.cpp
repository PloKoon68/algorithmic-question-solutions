//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

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
  int maxStep = 0;

  void path(bool left, int step, TreeNode* node) {
    if(!node)
      return;

    maxStep = maxStep < step? step: maxStep;

    path(true, (!left)? step+1: 1, node->left);
    path(false, (left)? step+1: 1, node->right);
  }

  int longestZigZag(TreeNode* root) {
    path(true, 1, root->left);
    path(false, 1, root->right);
    return maxStep;
  }
};

