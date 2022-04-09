/**
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * 方法一：基于双端队列的层序遍历
 * 关键在于保持双端队列中的结点顺序永远是从左往右的
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) return ret;
    deque<TreeNode*> q;  // 双端队列
    vector<int> tracking;
    q.push_back(root);
    bool r2l = false;  // 是否是从右往左遍历
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        if (r2l) {  // 右->左
          auto n = q.back();
          q.pop_back();
          tracking.push_back(n->val);
          // 头部入队，先右结点后左结点，保持双端队列中的结点顺序是从左往右的
          if (n->right) q.push_front(n->right);   
          if (n->left) q.push_front(n->left);
        } else {  // 左->右
          auto n = q.front();
          q.pop_front();
          tracking.push_back(n->val);
          if (n->left) q.push_back(n->left);
          if (n->right) q.push_back(n->right);
        }
      }
      ret.push_back(tracking);
      tracking.clear();
      r2l = !r2l;
    }
    return ret;
  }
};

/**
 * 方法二：普通层序遍历+输出列表翻转
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) return ret;
    queue<TreeNode*> q;
    vector<int> tracking;
    q.push(root);
    bool r2l = false;
    while (!q.empty()) {
      int size = q.size();
      // 普通的从左往右输出
      for (int i = 0; i < size; i++) {
        auto n = q.front();
        q.pop();
        tracking.push_back(n->val);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      if (r2l) // 如果这一层要求从右往左输出，翻转结果列表
        reverse(tracking.begin(), tracking.end());

      ret.push_back(tracking);
      tracking.clear();
      r2l = !r2l;
    }
    return ret;
  }
};