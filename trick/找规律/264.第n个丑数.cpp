/**
 * https://leetcode-cn.com/problems/ugly-number-ii/
 * https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode-solution-uoqd/
 * 方法一：小顶堆 + hash去重
 */
class Solution {
 public:
  int nthUglyNumber(int n) {
    // 小顶堆，存当前
    priority_queue<long, vector<long>, std::greater<long>> heap;
    heap.push(1);
    unordered_set<long> hash; // 所有已求出的丑数，去重
    hash.insert(1);
    long t[3] = {0, 0, 0};
    long ret = 0;
    while (n--) {
      // 将当前最小的丑数乘以 2、3、5 生成新的丑数，进堆
      long top = heap.top();
      heap.pop();
      ret = top;
      t[0] = top * 2;
      t[1] = top * 3;
      t[2] = top * 5;
      for (int i = 0; i < 3; i++) {
        if (!hash.count(t[i])) { // 不重复的，进堆
          heap.push(t[i]);
          hash.insert(t[i]);
        }
      }
    }
    return ret;
  }
};

/**
 * 方法二：递推
 */
class Solution1 {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    // 丑数一定是由之前的丑数乘以2、3、5得出的，存储每个乘数可乘的下一个丑数位置
    int p2 = 1, p3 = 1, p5 = 1;
    dp[1] = 1;
    // 求每一个丑数
    for (int i = 2; i <= n; i++) {
      // 由之前的丑数生成新的备选丑数
      int t2 = dp[p2] * 2;
      int t3 = dp[p3] * 3;
      int t5 = dp[p5] * 5;
      dp[i] = min(min(t2, t3), t5); // 取最小的为第 i 个丑数
      // 更新可乘的丑数位置
      if (dp[i] == t2) p2++;
      if (dp[i] == t3) p3++;
      if (dp[i] == t5) p5++;
    }
    return dp[n];
  }
};
