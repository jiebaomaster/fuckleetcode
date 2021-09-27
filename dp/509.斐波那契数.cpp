/**
 * https://leetcode-cn.com/problems/fibonacci-number/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye/dong-tai-gui-hua-xiang-jie-jin-jie#yi-fei-bo-na-qi-shu-lie
 */
class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    // 求 fibo 数列的实际只需要记住 f(n-1) 和 f(n-2)
    int pre = 1, cur = 1; 
    for (int i = 3; i <= n; i++) { // 一直求到 n
      int sum = pre + cur;
      pre = cur;
      cur = sum;
    }
    return cur;
  }
};