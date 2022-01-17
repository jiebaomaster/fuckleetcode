/**
 * https://leetcode-cn.com/problems/count-primes/
 * https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/
 * https://labuladong.github.io/algo/4/29/115/
 * 厄拉多塞筛法
 * 从每一个已知质数出发，筛选出它作为因数的所有合数
 */
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 1) return 0;
    vector<bool> isPrimes(n, true);
    // 从一个已知质数出发，求他作为因数的所有合数
    for (int i = 2; i < sqrt(n); i++) {
      if (isPrimes[i]) {
        // 2*i,3*i,4*i....k*i
        // 其中 k<i 的情况已被前面的质数筛选过，所以 k 直接从 i 开始
        for (int j = i * i; j < n; j += i) {
          isPrimes[j] = false;
        }
      }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++) {
      if (isPrimes[i]) {
        cnt++;
      }
    }
    return cnt;
  }
};