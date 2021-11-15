/**
 * https://leetcode-cn.com/problems/burst-balloons/
 * https://mp.weixin.qq.com/s/I0yo0XZamm-jMpG-_B3G8g
 * 
 * 1. 最简单的办法就是穷举戳气球的顺序，不同的戳气球顺序可能得到不同的分数，
 *    找出所有可能的分数中最高的。即用回溯算法求全排列问题
 * 
 * 2. dp[i][j] 为戳破 (i,j) 范围内的所有气球所得的最高分数，所求为 dp[0][n]
 *    因为每次戳气球获得的分数和相邻气球编号有关，需要逆向思考，确定额外的状态。
 *    设 (i,j) 范围内最后一个戳破的气球为 k，i<k<j，则戳破 k 时，和他相邻的正好是 i 和 j，
 *    则 dp[i][j] = max{ dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j] }
 *                        k 左侧      k 右侧     戳破 k 获得的分数
 */
class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    // dp[i][j] 为戳破 (i,j) 范围内的所有气球所得的最高分数
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    vector<int> knums(n + 2);
    knums[0] = knums[n + 1] = 1; // 不存在的气球分数为 1，在乘法中不起作用
    for (int i = 1; i <= n; i++) knums[i] = nums[i - 1];

    for (int i = n + 1; i >= 0; i--) {
      for (int j = i + 2; j <= n + 1; j++) {
        // 如果最后一个戳破的是 k（i<k<j）时，遍历取最大值
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = max(dp[i][j],
                         dp[i][k] + dp[k][j] + knums[i] * knums[k] * knums[j]
                        );
        }
      }
    }

    return dp[0][n + 1];
  }
};