/**
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/
 * 层序遍历，求每一层的宽度。
 * 宽度可由完全二叉树的下标表示
 * 父 i，left i*2，right i*2+1
 * 使用 unsigned long long 防止下标越界
 */
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    // 队列中保存 节点指针和本节点的下标
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 1});
    unsigned long long left, right;
    unsigned long long res = 1;
    while (!q.empty()) {
      int len = q.size();
      for (int i = 0; i < len; i++) {
        auto n = q.front();
        q.pop();
        if (n.first->left) {
          q.push({n.first->left, n.second * 2});
        }
        if (n.first->right) {
          q.push({n.first->right, n.second * 2 + 1});
        }
        if (i == 0) {
          left = n.second;
        }
        if (i == len - 1) {
          right = n.second;
          res = max(res, right - left + 1);
        }
      }
    }
    return res;
  }
};