/**
 * https://leetcode-cn.com/problems/invert-binary-tree/
 * 前中后层序都可以
 * 方法一：递归后序
 */
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return root;

    auto tmp = invertTree(root->right);
    root->right = invertTree(root->left);
    root->left = tmp;
    return root;
  }
};

/**
 * 方法二：迭代后序
 */
class Solution1 {
 public:
  TreeNode* invertTree(TreeNode* root) {
    auto p = root;
    TreeNode* pre = nullptr;
    stack<TreeNode*> st;

    while (p || !st.empty()) {
      while (p) {
        st.push(p);
        p = p->left;
      }

      p = st.top();
      if (!p->right || p->right == pre) {
        swap(p->left, p->right);
        st.pop();
        pre = p;
        p = nullptr;
      } else {
        p = p->right;
      }
    }
    return root;
  }
};