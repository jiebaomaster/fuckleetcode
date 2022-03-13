/**
 * https://leetcode-cn.com/problems/path-sum-ii/
 * 找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径
 */
class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (!root) return res;

    vector<int> tracking;
    tracking.push_back(root->val);
    backtrack(root, tracking, root->val, targetSum);
    return res;
  }
  void backtrack(TreeNode* root, vector<int>& tracking, int cur,
                 int targetSum) {
    if (!root->left && !root->right) {
      if (cur == targetSum) res.push_back(tracking);
      return;
    }
    if (root->left) {
      cur += root->left->val;
      tracking.push_back(root->left->val);
      backtrack(root->left, tracking, cur, targetSum);
      tracking.pop_back();
      cur -= root->left->val;
    }
    if (root->right) {
      cur += root->right->val;
      tracking.push_back(root->right->val);
      backtrack(root->right, tracking, cur, targetSum);
      tracking.pop_back();
      cur -= root->right->val;
    }
  }
};