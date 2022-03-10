/**
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * 方法一：简单递归，返回左右子树的最大高度
 */
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

/**
 * 方法二：层序遍历，记录层数
 */
class Solution1 {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int dep = 0;
    while (!q.empty()) {
      dep++;
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        auto n = q.front();
        q.pop();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
    }
    return dep;
  }
};