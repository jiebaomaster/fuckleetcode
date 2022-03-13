/**
 * https://leetcode-cn.com/problems/subtree-of-another-tree/
 * 先序遍历二叉树，判断从每一个结点开始的二叉树是否和 subRoot 相等
 */
class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (root->val == subRoot->val && isSameTree(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};