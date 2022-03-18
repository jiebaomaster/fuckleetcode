/**
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/
 */
class Solution {
 public:
  int cur = 0; // 最大路径的节点数
  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return cur - 1; // 求最大路径的边数，要减 1
  }
  // 求以 root 为根的树的直径
  int dfs(TreeNode* root) {
    if (!root) return 0;

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // 最大路径可能是不经过上层结点，由 l + root + r 构成
    cur = max(left + right + 1, cur);
    
    return max(left, right) + 1;
  }
};