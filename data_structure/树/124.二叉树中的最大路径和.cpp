/**
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 * 在树中沿父节点-子节点连接，从一个结点到另一个结点所构成的路径，求路径中各节点值的总和最大值
 */
class Solution {
 public:
  int maxLen;
  int maxPathSum(TreeNode* root) {
    maxLen = INT_MIN;
    doMaxPathSum(root);
    return maxLen;
  }

  // 求包含root结点的最大路径和
  int doMaxPathSum(TreeNode* root) {
    if (!root) return -1;
    int l = doMaxPathSum(root->left);
    int r = doMaxPathSum(root->right);

    int len = root->val;
    // 如果要包含root，且能作为上层路径的一部分，则只能是：
    // 1. 单独root；2. 左子路径+root；3. root+右子路径
    int tolen = max(len, max(len + l, len + r));
    // 最大路径可以不经过上层路径，即由 左子路径+root+右子路径 构成
    maxLen = max(maxLen, max(tolen, len + r + l));
    return tolen;
  }
};