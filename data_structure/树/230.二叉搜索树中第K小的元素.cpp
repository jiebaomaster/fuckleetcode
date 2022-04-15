/**
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
 * 中序遍历
 * 递归法
 */
class Solution {
 public:
  int res;
  int kthSmallest(TreeNode* root, int k) {
    find(root, k);
    return res;
  }
  bool find(TreeNode* root, int& k) {
    if (!root) return false;

    if (find(root->left, k)) return true;
    k--;
    if (!k) {
      res = root->val;
      return true;
    }
    return find(root->right, k);
  }
};

/**
 * 迭代法
 */
class Solution1 {
 public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    auto p = root;
    while (!stk.empty() || p) {
      while (p) {
        stk.push(p);
        p = p->left;
      }
      p = stk.top();
      stk.pop();
      k--;
      if (!k) return p->val;
      p = p->right;
    }
    return -1;
  }
};