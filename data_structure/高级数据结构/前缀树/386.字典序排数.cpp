/**
 * https://leetcode-cn.com/problems/lexicographical-numbers/
 * https://leetcode-cn.com/problems/lexicographical-numbers/solution/by-ac_oier-ktn7/
 * 方法一：10 叉字典树的前序遍历
 * 字典序数组相当于下列 10 叉树的前序遍历，
 * 类似字典树，从根节点到叶子结点的路径构成一个元素
 *            0
 *        /   |   \
 *       1    2 ...9
 *     // \  /｜
 *   0 1...9 0 1...
 *  /
 * 0...
 *
 *
 */
class Solution {
 public:
  vector<int> res;
  vector<int> lexicalOrder(int n) {
    for (int i = 1; i <= 9; i++)  // 第一级 1～9
      preOrder(i, n);
    return res;
  }
  // 10 叉树的前序遍历
  void preOrder(int cur, int limit) {
    if (cur > limit) return;
    res.push_back(cur);
    for (int i = 0; i <= 9; i++)  // 下一级子树 0～9
      preOrder(cur * 10 + i, limit);
  }
};

/**
 * 方法二：模拟法
 * nums 的下一个字典序整数应该是
 *  nums*10
 *  或者 nums/10 + 1
 */
class Solution1 {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    int num = 1;
    for (int i = 0; i < n; i++) {
      res.push_back(num);
      // 求 nums 的下一个字典序整数
      if (num * 10 <= n) {
        num *= 10; // 末尾添加 0
      } else {
        // 向前回溯，即减小一位
        // 109 之后的是 11
        while (num % 10 == 9 || num + 1 > n) {
          num /= 10;
        }
        num++;
      }
    }
    return res;
  }
};