//https://leetcode.com/problems/check-completeness-of-a-binary-tree/


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
    bool isCompleteTree(TreeNode* root) {
      unordered_map<string, int> lvl;  
        lvl["maxLevel"] = -1;
        lvl["step"] = 0;
        lvl["bool"] = true;

        solve(root, lvl, 0);
        
        return lvl["bool"];   
    }

public:
    void solve(TreeNode* node, unordered_map<string, int> &lvl, int level) {
    if(!lvl["bool"])
    return;
 
  
        
        if(node->left)
          solve(node->left, lvl, level+1);
        else {
          if(lvl["step"] == 0) {
            lvl["step"]++;
            lvl["maxLevel"] = level;
          }
          else if(lvl["step"] == 1){
            if(level > lvl["maxLevel"])
              lvl["bool"] = false;
            else if(level == lvl["maxLevel"] - 1) {
              lvl["step"]++;
              lvl["maxLevel"]--;
              }
            else if(level < lvl["maxLevel"])
              lvl["bool"] = false;
          }
          else if(lvl["step"] == 2){
            if(level != lvl["maxLevel"])
              lvl["bool"] = false;
          }
            
        }
  
        if(!lvl["bool"])
        return;
  
        if(node->right)
          solve(node->right, lvl, level+1);
        else {
          if(lvl["step"] == 1) {
            if(level == lvl["maxLevel"] - 1) {
              lvl["step"]++;
              lvl["maxLevel"]--;
            }
             else if(level > lvl["maxLevel"]) {
               lvl["bool"] = false;
             } 
            else if(level < lvl["maxLevel"])
              lvl["bool"] = false;
          }
           else if(lvl["step"] == 2){
            if(level != lvl["maxLevel"])
              lvl["bool"] = false;
          }
        }
        }
};
