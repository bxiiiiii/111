#include <algorithm>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> re;
    if (!root) {
      return re;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      re.push_back(vector<int>());
      for (int i = 1; i <= size; i++) {
        auto node = q.front();
        q.pop();
        re.back().push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    for (int i = 0; i < re.size(); i++) {
      if (i % 2 != 0) {
        reverse(re[i].begin(), re[i].end());
      }
    }
    return re;
  }
};