/**
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * 后序遍历的迭代写法，关键在于判断右子树是否已被访问过
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st; // 暂存左子树的结点
    auto p = root;
    TreeNode* pre = nullptr;
    while (p || !st.empty()) {
      while (p) { // 走到左下角
        st.push(p);
        p = p->left;
      }
      p = st.top();
      // 右子树不存在 或者 右子树已经被遍历过，则访问根结点
      if (!p->right || p->right == pre) {
        res.push_back(p->val);
        st.pop();
        pre = p; // 记录结点的访问情况，在返回上层时判断右结点是否已经访问过
        p = nullptr; // 右子树不存在，返回上层
      } else { // 走右子树
        p = p->right;
      }
    }
    return res;
  }
};