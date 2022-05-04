/**
 * https://leetcode-cn.com/problems/symmetric-tree/
 * 方法一：递归对称遍历
 * 双递归
 */
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return doChange(root->left, root->right);
  }
  bool doChange(TreeNode* left, TreeNode* right) {
    // 空的结点是对称的
    if (!left && !right) return true;
    // 非空和空不对称，结点值不相等不对称
    if (!left || !right || left->val != right->val) return false;
    // 递归判断当前结点的子节点是否对称，一组2个结点有4个子节点，即两组需要判断
    return doChange(left->left, right->right) && doChange(left->right, right->left);
  }
};

/**
 * 方法二：层序遍历，特殊的入队方式保证队列中的结点
 * 按照对称结点 {left,right} 成组存放，不存在的结点用 null 占位
 */
class Solution1 {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      // 取头两个结点，即对称结点 {left，right}
      auto left = q.front();
      q.pop();
      auto right = q.front();
      q.pop();
      if (!left && !right) continue;
      if (!left || !right || (left->val != right->val)) return false;

      // 将子节点按对称方式入队
      //  1   3   4   2
      // l.l l.r r.l r.r
      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }
    return true;
  }
};