/**
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * 方法一：递归
 */
class Solution {
 public:
  vector<int> res;
  vector<int> preorderTraversal(TreeNode* root) {
    doTraversal(root);
    return res;
  }
  void doTraversal(TreeNode* root) {
    if (!root) return;

    res.push_back(root->val);
    doTraversal(root->left);
    doTraversal(root->right);
  }
};

/**
 * 方法二：迭代
 */
class Solution1 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    auto p = root;
    stack<TreeNode*> s; // 暂存左子树的结点
    while (p || !s.empty()) {
      while (p) { // 依次访问左子树，直到左下角
        res.push_back(p->val);
        s.push(p);
        p = p->left;
      }
      // 访问左子树最下层结点的右子树
      p = s.top()->right;
      s.pop();
    }
    return res;
  }
};