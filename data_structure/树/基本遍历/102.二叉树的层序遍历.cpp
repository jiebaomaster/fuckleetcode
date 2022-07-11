/**
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * 方法一：bfs
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

/**
 * 方法二：dfs
 * 前序遍历，传递深度
 */
class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> levelOrder(TreeNode* root) {
    dfs(root, 0);
    return res;
  }

  void dfs(TreeNode* root, int level) {
    if (!root) return;

    if (res.size() <= level) {
      res.resize(level + 1);
    }
    res[level].push_back(root->val);
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }
};