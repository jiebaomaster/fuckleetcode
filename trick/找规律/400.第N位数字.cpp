/**
 * https://leetcode-cn.com/problems/nth-digit/
 * https://leetcode-cn.com/problems/nth-digit/solution/gong-shui-san-xie-jian-dan-mo-ni-ti-by-a-w5wl/
 * 
 * 先算出是几位数，再求出具体是哪个数
 */
class Solution {
 public:
  int findNthDigit(int n) {
    // 求得目标是 len 位数
    int len = 1;
    while (n - len * 9 * pow(10, len - 1) > 0) {
      n -= len * 9 * pow(10, len - 1);
      len++;
    }
    // len 位数的最小值为 s
    int s = pow(10, len - 1);
    // 此时 n 为距离目标数的总位数
    // 每个 len 位数长度都为 len，则可求得目标数 t
    int t = s + (n - 1) / len;
    // n%len 为 0 说明是 t 的最后一位
    if (n % len == 0)
      return t % 10;
    else // 否则是 t 的从左往右数第 n%len 位
      return (t / (int)pow(10, len - n % len)) % 10;
  }
};