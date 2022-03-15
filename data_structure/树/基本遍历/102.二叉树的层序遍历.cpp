/**
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * 双循环法进行层序遍历
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    vector<int> level;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int cnt = q.size(); // 当前队列中放着某一层的结点
      // 这里终止条件不能是 q.size()，因为 q 的大小在遍历时一直在变化
      for (int i = 0; i < cnt; i++) { // 每次把一层的结点都遍历完
        TreeNode* n = q.front();
        q.pop();
        level.push_back(n->val);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      res.push_back(level);
      level.clear();
    }
    return res;
  }
};