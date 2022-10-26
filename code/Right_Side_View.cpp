#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> que;
    vector<int> re;
    if (root) {
      que.push(root);
    }
    while (!que.empty()) {
      int qsize = que.size();
      for (int i = 0; i < qsize; i++) {
        auto node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
        if (i == qsize - 1) {
          re.push_back(node->val);
        }
      }
    }
    return re;
  }
};