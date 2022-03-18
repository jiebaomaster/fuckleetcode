/**
 * https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/
 * 若记录下每个节点的父结点，就能将树转化为图，然后再从 target 出发找到图中距离为 k 的结点
 */
class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> res;

    unordered_map<TreeNode*, TreeNode*> parent;
    parent.insert({root, nullptr});
    // 先找到父结点
    getParent(root, parent);
    // bfs 寻找第 k 层
    queue<TreeNode*> q;
    unordered_set<TreeNode*> inq; // 记录是否已经入过队，防止走回头路
    inq.insert(target);
    q.push(target);
    while (!q.empty()) {
      if (k == 0) {
        break;
      }
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();

        if (n->left && inq.find(n->left) == inq.end()) {
          q.push(n->left);
          inq.insert(n->left);
        }
        if (n->right && inq.find(n->right) == inq.end()) {
          q.push(n->right);
          inq.insert(n->right);
        }
        if (parent[n] && inq.find(parent[n]) == inq.end()) {
          q.push(parent[n]);
          inq.insert(parent[n]);
        }
      }
      k--;
    }
    while (!q.empty()) {
      res.push_back(q.front()->val);
      q.pop();
    }
    return res;
  }
  // 记录每个结点的父结点
  void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!root) return;

    if (root->left) {
      parent.insert({root->left, root});
      getParent(root->left, parent);
    }
    if (root->right) {
      parent.insert({root->right, root});
      getParent(root->right, parent);
    }
  }
};