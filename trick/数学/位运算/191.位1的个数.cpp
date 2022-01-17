/**
 * https://leetcode-cn.com/problems/number-of-1-bits/
 * 求二进制数中1的位数
 * 基本方法：10 进制数转 2 进制数，判断每一位是否为 0
 */
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    // 除 2 取余法
    while (n != 0) {
      if (n % 2 == 1)  // 当前位的数字
        count++;
      n >>= 1;  // 下一位
    }
    return count;
  }
};

/**
 * https://labuladong.gitee.io/algo/4/30/114/
 * 位操作 n&(n-1) 作用是消除数字 n 的二进制表示中的最后一个 1
 */
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      n = n & (n - 1);
      count++;
    }
    return count;
  }
};