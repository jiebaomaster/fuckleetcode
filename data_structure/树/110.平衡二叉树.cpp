/**
 * https://leetcode.cn/problems/balanced-binary-tree/
 *
 */
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    dfs(root);
    return f;
  }
  bool f = true;
  int dfs(TreeNode* root) {
    if (!f) return 0;
    if (!root) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if (abs(left - right) > 1) {
      f = false;
    }
    return max(left, right) + 1;
  }
};