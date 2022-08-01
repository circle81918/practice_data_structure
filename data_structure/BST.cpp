#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

class BST {
  public:
    BST() : root(nullptr){}

    TreeNode* insertNode(TreeNode* root, int val) {
      if (!root) {
        TreeNode* node = new TreeNode(val);
        return node;
      }

      if (root->val < val)
        root->right = insertNode(root->right, val);
      else
        root->left = insertNode(root->left, val);
      return root;
    }

    // Contain memory leak issue, need refactor later
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root)
        return nullptr;

      if (root->val == key) {
        if (!root->right)
          return root->left;
        else {
          TreeNode* cur = root->right;
          while (cur->left) cur = cur->left;
          std::swap(root->val, cur->val);
        }
      }
      root->left = deleteNode(root->left, key);
      root->right = deleteNode(root->right, key);
      return root;
    }

    void inorder(TreeNode* root) {
      if (root == NULL)
        return;
      inorder(root->left);
      std::cout << root->val << " ";
      inorder(root->right);
    }

    operator TreeNode*() const { return root; }

  public:
    TreeNode *root;
};

int main() {
  BST t;
  t.root = t.insertNode(t, 20);
  t.root = t.insertNode(t, 25);
  t.root = t.insertNode(t, 15);
  t.root = t.insertNode(t, 10);
  t.root = t.insertNode(t, 30);
  t.inorder(t);
  std::cout<<std::endl;
  t.root = t.deleteNode(t, 20);
  t.root = t.deleteNode(t, 15);
  t.inorder(t);
  
  system("pause");
  return 0;
}