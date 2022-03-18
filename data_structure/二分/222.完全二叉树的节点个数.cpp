/**
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/wan-quan-er-cha-shu-de-jie-dian-ge-shu-by-leetco-2/
 */
class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    int level = 0;
    auto p = root;
    // 计算树的高度，从 0 开始计数
    while (p->left) {
      level++;
      p = p->left;
    }
    if (level == 0) return 1;
    // 最下面一层的结点编号，最小为 2^n，最大为 2^(n-1) - 1
    // 在 [l,r) 中查找第一个不存在的结点编号
    int l = 1 << level;
    int r = (1 << (level + 1));
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (!exist(level, root, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l - 1; // 结点个数为第一个不存在的结点编号减 1
  }
  /**
   * @brief 判断编号为 target 的结点在以 root 为根的树中是否存在，结点从 1 开始编号
   * 如果第 k 个节点位于第 h 层，则 k 的二进制表示包含 h+1 位，二进制的每一位表示
   * 从根结点到目标结点到路径，0 表示移动到左子节点，1 表示移动到右子节点。
   */
  bool exist(int level, TreeNode* root, int target) {
    int c = 1 << (level - 1); // 从第2位开始
    while (c) { // 沿着路径向下走
      if (target & c)
        root = root->right;
      else
        root = root->left;

      // 路径上的结点不存在，则 target 不存在
      if (!root) return false;
      // 判断下一位
      c >>= 1;
    }
    return true;
  }
};