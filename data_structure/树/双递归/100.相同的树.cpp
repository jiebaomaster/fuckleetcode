/**
 * https://leetcode-cn.com/problems/same-tree/
 * 方法一：双递归，判断两棵树中对应的结点是否相同
 */
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

/**
 * 方法二：层序遍历，特殊的入队方式保证队列中的结点按照两棵树中
 * 对应结点 {left,left} {right,right} 成组存放，不存在的结点用 null 占位
 */
class Solution1 {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> que;
    que.push(p);
    que.push(q);
    while (!que.empty()) {
      // 取头两个结点，即对称结点 {left，right}
      auto left = que.front();
      que.pop();
      auto right = que.front();
      que.pop();
      if (!left && !right) continue;
      if (!left || !right || (left->val != right->val)) return false;

      // 将子节点按对应方式入队
      // 左节点和左节点比较
      que.push(left->left);
      que.push(right->left);
      // 右结点和右结点比较
      que.push(left->right);
      que.push(right->right);
    }
    return true;
  }
};