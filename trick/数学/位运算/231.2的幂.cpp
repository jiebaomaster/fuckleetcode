/**
 * https://leetcode-cn.com/problems/power-of-two/
 * https://labuladong.gitee.io/algo/4/30/114/
 * 判断一个数是否为 2 的幂
 * 位操作 n&(n-1) 作用是消除数字 n 的二进制表示中的最后一个 1
 * 一个数如果是 2 的指数，那么它的二进制表示一定只含有一个 1
 */
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    if ((n & (n - 1)) == 0) return true;
    return false;
  }
};