//https://leetcode.com/problems/sum-root-to-leaf-numbers/description/



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
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }

public:
    int solve(TreeNode* node, int num) { 
  num += node->val;
  int sum = 0;
  if(node->left)    
      sum += solve(node->left, num * 10);
  if(node->right)
      sum += solve(node->right, num * 10);

  if(!node->left && !node->right)
    return num;
  
  return sum;
}

};
