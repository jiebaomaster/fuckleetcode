/**
 * https://leetcode-cn.com/problems/longest-univalue-path/
 * 
 */
class Solution {
 public:
  int maxLen = 1;
  int longestUnivaluePath(TreeNode* root) {
    dfs(root);
    return maxLen - 1;
  }
  // 经过 root 的同值路径长度
  int dfs(TreeNode* root) {
    if (!root) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    // 如果子节点的值不等于root的值，则不能算作同值路径
    if (root->left && root->val != root->left->val) left = 0;
    if (root->right && root->val != root->right->val) right = 0;
    // 计算路径时左右分支都能算
    maxLen = max(maxLen, 1 + left + right);
    // 返回时只返回更大的那个分支
    return max(left, right) + 1;
  }
};