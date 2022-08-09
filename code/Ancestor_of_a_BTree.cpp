#include <iostream>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* ans;
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
  }

  bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return false;
    }

    bool inCurrentNode = (root->val == p->val) || (root->val == q->val);
    bool inLeft = dfs(root->left, p, q);
    bool inRight = dfs(root->right, p, q);

    if ((inLeft && inRight) || (inCurrentNode && (inLeft || inRight))) {
        ans = root;
    }

    return inCurrentNode || inLeft || inRight;
  }
};