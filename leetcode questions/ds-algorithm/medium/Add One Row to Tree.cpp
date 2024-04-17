//https://leetcode.com/problems/add-one-row-to-tree/description/



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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            root = newRoot;
        }
        else
            addRow(root, &val, &depth, 1);
        return root;
    }
    void addRow(TreeNode* node, int* val, int* depth, int level) {
        if(!node) return;

        if(level == *depth - 1) {
            //save childs
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            //create new nodes
            TreeNode* newLeft = new TreeNode(*val);
            TreeNode* newRight = new TreeNode(*val);

            //connect them
            node->left = newLeft;
            node->right = newRight;

            newLeft->left = left;
            newRight->right = right;
            return;
        }

        addRow(node->left, val, depth, level+1);
        addRow(node->right, val, depth, level+1);
    }
};
