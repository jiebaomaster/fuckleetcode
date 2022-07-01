/**
 * https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      vector<int> level;
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();
        level.push_back(n->val);
        for (auto& c : n->children) {
          q.push(c);
        }
      }
      res.push_back(level);
    }
    return res;
  }
};