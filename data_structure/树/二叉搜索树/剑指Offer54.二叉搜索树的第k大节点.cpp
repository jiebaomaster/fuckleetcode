/**
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 * 二叉搜索树的中序遍历为升序数组
 * 反向中序遍历二叉搜索树，直到第 k 个结点，即为第 k 大的数字
 * 方法一：迭代法反向中序遍历
 */
class Solution {
 public:
  int kthLargest(TreeNode* root, int k) {
    if (!root) return -1;
    stack<TreeNode*> st;
    auto p = root;
    while (!st.empty() || p) {
      while (p) {
        st.push(p);
        p = p->right;
      }
      auto n = st.top();
      st.pop();
      k--;
      if (k == 0) return n->val;

      p = n->left;
    }
    return -1;
  }
};

/**
 * 方法二：递归反向中序遍历
 */
class Solution1 {
 public:
  int kthLargest(TreeNode* root, int k) { return doFind(root, &k)->val; }
  TreeNode* doFind(TreeNode* root, int* k) {
    if (!root) return nullptr;

    auto right = doFind(root->right, k);
    if (right) return right;  // 在右子树找到，直接返回

    (*k)--;                    // 更新当前遍历到的结点数
    if (*k == 0) return root;  // 当前结点为第 k 个，直接返回

    // 不在右子树的话，必在左子树
    auto left = doFind(root->left, k);
    return left;
  }
};