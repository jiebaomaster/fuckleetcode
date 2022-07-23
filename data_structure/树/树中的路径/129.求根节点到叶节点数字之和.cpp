/**
 * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 * 从根节点到叶节点构成一条路径，计算从根节点到叶节点生成的 所有数字之和
 * 方法一：递归，传递当前路径构成的数给下一层，直到叶子结点时累加
 */
class Solution {
 public:
  int sum;
  int sumNumbers(TreeNode* root) {
    sum = 0;
    travel(root, 0);
    return sum;
  }
  void travel(TreeNode* root, int cur) {
    if (!root) return;
    // 计算从根结点到当前结点构成的数字，前面路径的数字放大一位
    int tmp = cur * 10 + root->val;
    travel(root->left, tmp);
    travel(root->right, tmp);
    // 到达叶子结点，累加和
    if (!root->right && !root->left) sum += tmp;
  }
};

/**
 * 方法二：层序遍历，在结点原地修改 val 记录当前路径构成的数
 */
class Solution1 {
 public:
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        auto n = q.front();
        q.pop();
        if (n->left) {
          // 在结点原地修改 val 记录当前路径构成的数
          n->left->val = 10 * n->val + n->left->val;
          q.push(n->left);
        }
        if (n->right) {
          n->right->val = 10 * n->val + n->right->val;
          q.push(n->right);
        }
        if (!n->right && !n->left) {  // 到达叶子结点，累加和
          sum += n->val;
        }
      }
    }
    return sum;
  }
};