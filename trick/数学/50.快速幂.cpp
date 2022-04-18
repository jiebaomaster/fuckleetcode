/**
 * https://leetcode-cn.com/problems/powx-n/
 * 方法一：从上到下的递归计算
 */
class Solution {
 public:
  double myPow(double x, int n) {
    auto tmp = doPow(x, n);
    return n < 0 ? 1 / tmp : tmp;
  }
  double doPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    auto tmp = doPow(x, n / 2); // x^(n/2)
    tmp *= tmp;
    if (n % 2) tmp *= x;
    return tmp;
  }
};
/**
 * 方法二：迭代
 * 
 */
class Solution1 {
 public:
  double myPow(double x, int n) {
    auto tmp = doPow(x, n);
    return n < 0 ? 1 / tmp : tmp;
  }
  double doPow(double x, int n) {
    double res = 1;
    // 可看作将十进制指数转化为二进制，逢 1 则乘当前阶的幂
    while (n) {
      if (n % 2) res *= x;
      x *= x; // base作指数放大
      n /= 2;
    }

    return res;
  }
};