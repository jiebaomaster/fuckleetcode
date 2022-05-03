/**
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * https://labuladong.gitee.io/algo/4/29/110/
 */
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    // 二叉树不会走回头路，不用 visited
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      depth++;
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();
        if (!n->left && !n->right) {
          return depth;
        }
        if (n->left) {
          q.push(n->left);
        }
        if (n->right) {
          q.push(n->right);
        }
      }
    }
    return 0;
  }
};