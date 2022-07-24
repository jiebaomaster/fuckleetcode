/**
 * https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/
 * 方法一：bfs null不入队
 */
class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    // 是否碰到了 null，碰到 null 之后都得是 null
    bool needNull = false;
    while (!q.empty()) {
      int cnt = q.size();
      for (int i = 0; i < cnt; i++) {
        auto n = q.front();
        q.pop();

        if (n->left) {
          // 碰到 null 之后不能出现非空节点
          if (needNull) return false;
          q.push(n->left);
        } else { // 记录碰到 null
          needNull = true;
        }
        if (n->right) {
          // 碰到 null 之后不能出现非空节点
          if (needNull) return false;
          q.push(n->right);
        } else { // 记录碰到 null
          needNull = true;
        }
      }
    }
    return true;
  }
};

/**
 * 方法二：bfs null入队
 */
class Solution1 {
 public:
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool needNull = false;
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      if (!n) break; // 碰到 null 之后停止遍历
      q.push(n->left); // null 也入队
      q.push(n->right);
    }
    // 判断队列中是否还有非空节点
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      if (n) return false;
    }
    return true;
  }
};