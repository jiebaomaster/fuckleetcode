/**
 * https://leetcode.cn/problems/binary-tree-paths/
 */
class Solution {
 public:
  vector<string> res;
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<int> track;
    dfs(root, track);
    return res;
  }

  void dfs(TreeNode* root, vector<int>& track) {
    if (!root) {
      return;
    }

    if (!root->left && !root->right) {
      string s;
      for (int n : track) {
        s += to_string(n) + "->";
      }
      s += to_string(root->val);
      res.push_back(s);
      return;
    }

    track.push_back(root->val);
    dfs(root->left, track);
    dfs(root->right, track);
    track.pop_back();
  }
};