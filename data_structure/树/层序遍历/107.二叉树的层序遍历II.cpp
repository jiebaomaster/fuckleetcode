/**
 * https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 * 基本的层序遍历，最后反转一下结果集即可
 */
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;

    q.push(root);
    while (!q.empty()) {
      vector<int> cur;
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();
        cur.push_back(n->val);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      res.push_back(cur);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};