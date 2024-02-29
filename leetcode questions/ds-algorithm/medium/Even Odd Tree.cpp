//https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> queue;
        int level = 0;
        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev_val)) ||
                    (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev_val))) return false;

                prev_val = node->val;

                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            level++;
        }
        return true;
    }
};
