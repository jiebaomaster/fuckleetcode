/**
 * https://leetcode-cn.com/problems/ones-and-zeroes/
 * https://programmercarl.com/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.html#%E6%80%9D%E8%B7%AF
 * 从 strs 中取，在满足 (m,n) 条件下最多能取出几个字符串
 * 因为每一种物品只有一个，所以本题是一个 01 背包问题，只是背包容量有两个维度
 * 
 * dp[k][i][j] 为从 strs 的前 k 个物品中选，“可以”放入容量为 (i,j) 的背包最多物品数量
 * 要想放入 strs[k]，背包的两个维度都要满足
 * max(dp[k - 1][i][j], dp[k - 1][i - num0][j - num1] + 1)
 */
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<vector<int>>> dp(
        strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

    for (int k = 1; k <= strs.size(); k++) {
      int num0 = 0, num1 = 0;
      // 统计 strs[k] 中 0 和 1 的个数
      for (char c : strs[k - 1]) {
        if (c == '0')
          num0++;
        else
          num1++;
      }

      // 两维度的约束
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
          if (i < num0 || j < num1) {
            dp[k][i][j] = dp[k - 1][i][j];
          } else { // 要想放入 strs[k]，背包的两个维度都要满足
            dp[k][i][j] =
                max(dp[k - 1][i][j], dp[k - 1][i - num0][j - num1] + 1);
          }
        }
      }
    }

    return dp[strs.size()][m][n];
  }
};