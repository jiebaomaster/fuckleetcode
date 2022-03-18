/**
 * https://leetcode-cn.com/problems/path-sum/
 * 判读是否存在一条从根结点开始的路径的节点和等于target
 * 方法一：层序遍历，自顶向下传递路径和，在叶子结点时判断
 */
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();
        // 叶子节点，判断路径和是否等于 target
        if (!n->left && !n->right && n->val == targetSum) return true;
        if (n->left) {
          // 修改子节点的值，传递路径和
          n->left->val += n->val;
          q.push(n->left);
        }
        if (n->right) {
          n->right->val += n->val;
          q.push(n->right);
        }
      }
    }
    return false;
  }
};

/**
 * 方法二：递归判断子节点是否存在路径等于 target-root.val
 */
class Solution1 {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    if (!root->left && !root->right) // 叶子结点，可以直接判断
      return root->val == targetSum;

    // 左右有一个存在即可
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};