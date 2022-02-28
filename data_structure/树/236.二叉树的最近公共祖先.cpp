/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * 求最小公共祖先，需要从底向上遍历，那么二叉树，只能通过后序遍历（即：回溯）实现从低向上的遍历方式。
 */
class Solution {
 public:
  // 在树中寻找pq的最近公共祖先
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    // 递归地在左右两个子树中寻找
    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);
    if (l && r) { // 左右返回都不为空，说明当前节点是目标节点，因为这里是倒叙遍历
      return root;
    } else if (l) { // 左右返回有一个不为空，说明pq在不为空的那个子树上
      return l;
    } else if (r) {
      return r;
    } else { // 左右返回都为空，说明pq不在以root为根的子树上，需要换一条遍历路径
      return nullptr;
    }
  }
};