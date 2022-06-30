/**
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 区别于第 236 题，BST 中可以借助节点的值确定下一步遍历的方向
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;

    // 借助节点的值确定下一步遍历的方向
    if (root->val < p->val && root->val < q->val) { // pq 都大于 root，那么 pq 都在 root 右子树上
      return lowestCommonAncestor(root->right, p, q);
    } else if (root->val > p->val && root->val > q->val) { // pq 都小于 root，那么 pq 都在 root 左子树上
      return lowestCommonAncestor(root->left, p, q);
    } else // pq 在 root 的两边，那么 root 就是最近公共祖先
      return root;
  }
};