

void arrToBinary(TreeNode* root, int i, int* arr, int size) {
  if(2*i - 1 < size && !arr[2*i - 1]) {
    root->left = new TreeNode(arr[2*i - 1]);
    arrToBinary(root->left, 2*i, arr, size);
  }
  if(2*i < size && arr[2*i]) {
    root->right = new TreeNode(arr[2*i]);
    arrToBinary(root->right, 2*i + 1, arr, size);
  }
}

int main() {
  int arr[17] = {1,0,1,1,1,0,0,1,1,0,1,0,0,0,1,0,1};
  TreeNode* root = new TreeNode(arr[0]);

  arrToBinary(root, 1, arr, 17);
  cout << root->right->left->val;
  
  return 0;
}
