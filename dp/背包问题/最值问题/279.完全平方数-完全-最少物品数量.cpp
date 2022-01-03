/**
 * https://leetcode-cn.com/problems/perfect-squares/
 * 本题也是求最少使用物品数问题，只是备选物品没有直接给出，参考 322.零钱兑换1
 * 组合数的写法
 */
class Solution {
 public:
  int numSquares(int n) {
    vector<int> nums;
    int k = 1;
    while (k * k <= n) { // 产生备选的完全平方数
      nums.push_back(k * k);
      k++;
    }

    vector<vector<int>> dp(nums.size() + 1, vector<int>(n + 1));

    // dp[i][0] = 0
    for (int m = 1; m <= n; m++) dp[0][m] = 10050;
    for (int i = 1; i <= nums.size(); i++) { // 遍历物品
      for (int j = 1; j <= n; j++) { // 遍历容量
        if (j < nums[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = min(dp[i - 1][j], dp[i][j - nums[i - 1]] + 1);
      }
    }

    return dp[nums.size()][n];
  }
};


/**
 * https://programmercarl.com/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html
 * 排列的写法
 */
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= n; i++) { // 遍历容量
      for (int k = 1; k * k <= i; k++) { // 遍历物品，备选数为 k*k
        dp[i] = min(dp[i], dp[i - k * k] + 1);
      }
    }

    return dp[n];
  }
};