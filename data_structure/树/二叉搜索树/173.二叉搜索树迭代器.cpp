/**
 * https://leetcode.cn/problems/binary-search-tree-iterator/
 * 相当于把二叉树中序遍历的迭代写法拆分开来，每一步取一个遍历出的数
 */
class BSTIterator {
 public:
  stack<TreeNode*> st;
  TreeNode* cur;
  BSTIterator(TreeNode* root) { cur = root; }

  int next() {
    while (cur) {
      st.push(cur);
      cur = cur->left;
    }

    auto n = st.top();
    st.pop();

    cur = n->right;
    return n->val;
  }

  bool hasNext() { return cur || !st.empty(); }
};