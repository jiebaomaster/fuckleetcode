/**
 * https://leetcode-cn.com/problems/validate-binary-search-tree/
 * 二叉搜索树要求中序遍历是严格递增的
 * 只需要在中序遍历时记录下上一个遍历到的树是多少，并与本次遍历的数比较
 * 
 * 方法一：递归中序遍历
 */
class Solution {
 public:
  // 这里用指针指向null标志第一个遍历到的数没有上一个，比用int的边界值标志更好
  // 记录上一次遍历到数的值
  int* last = nullptr; 
  bool isValidBST(TreeNode* root) {
    if (!root) return true;

    if (!isValidBST(root->left)) return false;

    // 与当前值比较
    if (last && *last >= root->val) return false;
    last = &root->val; // 更新上一个遍历的数

    return isValidBST(root->right);
  }
};

/**
 * 方法二：迭代中序遍历
 */
class Solution1 {
 public:
  int* last = nullptr;
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st;
    auto p = root;
    int* last = nullptr;
    while (p || !st.empty()) {
      while (p) {
        st.push(p);
        p = p->left;
      }
      p = st.top();
      st.pop();
      if (last && *last >= p->val) return false;
      last = &p->val;

      p = p->right;
    }
    return true;
  }
};