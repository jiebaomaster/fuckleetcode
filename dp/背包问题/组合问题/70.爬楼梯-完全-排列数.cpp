/**
 * https://leetcode-cn.com/problems/climbing-stairs/
 * https://programmercarl.com/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E7%89%88%E6%9C%AC.html
 * 
 * 这道题是一道简单的 dp 问题，dp[i] = dp[i-1] + dp[i-2]
 */
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int dp = 0, dp_1 = 2, dp_2 = 1;
    int i = 3;
    while (i++ <= n) {
      dp = dp_1 + dp_2;
      dp_2 = dp_1;
      dp_1 = dp;
    }
    return dp;
  }
};

/**
 * 可以将本题看作是背包问题，每次爬 1 或 2 个台阶即物品 nums[]={1,2}，
 * 目标层数 n 是背包容量，每一阶可以重复使用，例如跳了 1 阶，还可以继续跳 1 阶，
 * 则是完全背包，{1,2} 和 {2,1} 不是一个方法，即求排列数
 * 转化为背包问题有个好处是可以求得每次爬 1/2/3... 任意级的方法数
 * 
 * 设 dp[i] 表示爬上 i 楼的方法数，
 *  可以先爬 i-1 （dp[i-1]）最后再爬 1 阶
 *  可以先爬 i-2 （dp[i-2]）最后再爬 2 阶
 *  ......
 *  可以先爬 i-k （dp[i-k]）最后再爬 k 阶
 * 所以 dp[i] = dp[i-1] + dp[i-2] + ...
 */
class Solution {
 public:
  int climbStairs(int n) {
    // dp[i] 表示爬上 i 楼的方法数
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) { // 遍历容量
      // 选择每种爬法
      for (int k = 1; k <= 2; k++) { // 遍历物品
        if (k <= i) // 保证 dp[i - k] 存在
          dp[i] += dp[i - k];
      }
    }
    return dp[n];
  }
};
