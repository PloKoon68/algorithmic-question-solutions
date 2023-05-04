struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Visit the current node
    cout << root->val << " ";
    // Recursively traverse the left subtree
    preOrderTraversal(root->left);
    // Recursively traverse the right subtree
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    inOrderTraversal(root->left);
    // Visit the current node
    cout << root->val << " ";
    // Recursively traverse the right subtree
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    postOrderTraversal(root->left);
    // Recursively traverse the right subtree
    postOrderTraversal(root->right);
    // Visit the current node
    cout << root->val << " ";
}
