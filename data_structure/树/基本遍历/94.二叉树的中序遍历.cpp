/**
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 借助栈的迭代写法
 */
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> st; // 暂存左子树的结点
    TreeNode* cur = root;
    while (cur || !st.empty()) {
      while (cur) { // 走到左下角
        st.push(cur);
        cur = cur->left;
      }
      // 访问栈顶
      cur = st.top();
      st.pop();
      ret.push_back(cur->val);

      if (cur->right) // 如果有右子树，就走右子树
        cur = cur->right;
      else // 否则从栈中弹出一个
        cur = nullptr;
    }

    return ret;
  }
};