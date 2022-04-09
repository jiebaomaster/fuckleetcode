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
    int step = 1;
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        TreeNode* cur = q.front();
        q.pop();
        // 找到第一个叶子节点
        if (!cur->right && !cur->left) {
          return step;
        }
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
        step++;
      }
    }
    return 0;
  }
};