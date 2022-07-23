/**
 * https://leetcode.cn/problems/path-sum-iii/
 * 方法一：双递归
 * 本题的路径不一定到从根节点到叶子节点，可以是一部分，
 * 所以除了需要一重递归求从特定根节点开始满足要求的路径数，
 * 还需要一重递归以每一个节点作为根节点
 * 时间复杂度 O(n^2)
 */
class Solution {
 public:
  int res = 0;
  int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    preorder(root, targetSum, 0);
    // 递归，以每一个节点作为根节点
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return res;
  }
  // 递归求从特定根节点 root 开始满足要求的路径数
  void preorder(TreeNode* root, int targetSum, long cur) {
    if (!root) return;
    cur += root->val;
    if (cur == targetSum) {
      res++;
    }
    preorder(root->left, targetSum, cur);
    preorder(root->right, targetSum, cur);
  }
};

/**
 * 方法二：前缀和+回溯
 * https://leetcode.cn/problems/path-sum-iii/solution/qian-zhui-he-di-gui-hui-su-by-shi-huo-de-xia-tian/
 * 路径是从根节点到叶子节点的一部分，可以用是否存在满足要求的前缀和判断是否存在满足要求的路径
 * 注意，遍历完一个节点后需要回溯，确保前缀和中只有一条根节点到叶子节点的路径上的节点
 */
class Solution {
 public:
  int res = 0;
  unordered_map<long, int> prefix; // 记录一条根节点到叶子节点的路径上所有节点的前缀和
  int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    prefix[0] = 1;
    backtrace(root, targetSum, 0);
    return res;
  }

  void backtrace(TreeNode* root, int targetSum, long cur) {
    if (!root) return;
    cur += root->val;
    // 判断是否存在满足要求的前缀和
    // cur - prefix == targetSum
    if (prefix.count(cur - targetSum)) {
      res += prefix[cur - targetSum];
    }
    prefix[cur]++; // 添加当前节点的前缀和
    backtrace(root->left, targetSum, cur);
    backtrace(root->right, targetSum, cur);
    prefix[cur]--; // 回溯，确保前缀和中只有一条根节点到叶子节点的路径上的节点
  }
};