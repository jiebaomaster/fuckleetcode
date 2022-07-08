/**
 * https://leetcode.cn/problems/sum-of-left-leaves/
 */
class Solution {
 public:
  int res = 0;
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return res;
    // 判断 root 的左节点是不是叶子节点
    if (root->left && !root->left->left && !root->left->right)
      res += root->left->val;

    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);
    return res;
  }
};