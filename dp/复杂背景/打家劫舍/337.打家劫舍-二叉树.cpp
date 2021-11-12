/**
 * https://leetcode-cn.com/problems/house-robber-iii/
 * https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/
 * 
 * 状态：
 *  rob[root] 表示以 root 为根的子树，打劫所得的最大金额
 * 选择：
 *  对于每个节点 root，可以选择打劫或者不打劫
 *  1. 如果打劫 root，则 root 的儿子节点不可打劫，孙子节点可以打劫
 *     do_rob_root = nums[root] 本节点
 *                   + rob[root->left->left] + rob[root->left->right] 左孙子
 *                   + rob[root->right->left] + rob[root->right->right] 右孙子
 *  2. 如果不打劫 root，则 root 的儿子节点可以打劫，孙子节点可以打劫
 *     do_not_rob_root = rob[root->left] + rob[root->right]
 *  最终的答案只需取两种情况的最大值 rob[root] = max{do_rob_root, do_not_rob_root}
 */
class Solution {
 public:
  unordered_map<TreeNode*, int> root_val; // 备忘录
  
  int rob(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root_val.find(root) != root_val.end()) // 已解决的子问题直接返回
      return root_val[root];

    int do_rob = root->val; // 如果抢劫本节点
    if (root->left != nullptr)
      do_rob += rob(root->left->left) + rob(root->left->right);
    if (root->right != nullptr)
      do_rob += rob(root->right->left) + rob(root->right->right);

    int do_not_rob = rob(root->left) + rob(root->right); // 如果不抢劫本节点
    
    int res = max(do_rob, do_not_rob); // 取两种情况的最大值
    root_val[root] = res; // 记录

    return res;
  }
};