/**
 * https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 */
class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    int n_1 = 1;
    int n_2 = 0;
    while (n-- > 1) {
      int t = n_1 + n_2;
      if (t >= 1000000007) t -= 1000000007;
      n_2 = n_1;
      n_1 = t;
    }
    return n_1;
  }
};