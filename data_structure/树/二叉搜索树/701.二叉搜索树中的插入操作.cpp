/**
 * https://leetcode.cn/problems/insert-into-a-binary-search-tree/
 * 方法一：迭代，找到插入位置的父节点
 */
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    auto n = new TreeNode(val);
    // 空树，直接返回 n
    if (!root) return n;
    auto p = root;
    auto pre = p;
    // 找到插入的位置p，即其父节点 pre
    while (p) {
      pre = p;
      if (p->val > val) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
    // 插入
    if (pre->val > val) {
      pre->left = n;
    } else {
      pre->right = n;
    }
    return root;
  }
};

/**
 * 方法二：递归
 */
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (root->val > val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);

    return root;
  }
};