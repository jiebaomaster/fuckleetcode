/**
 * https://leetcode-cn.com/problems/maximum-subarray-sum-with-one-deletion/
 * 求最大连续子序列和，但该连续子序列允许删除一个数，也可以不删除
 * 
 * 类似股票买卖问题，将是否进行删除看作一种状态
 * 设 dp[i][0] 为不删除时，以 i 结尾的最大连续子序列和，即为基本类型，参考 53 题
 *    dp[i][1] 为删除一个数后，到 i 为止的最大连续子序列和
 *          = max{ dp[i - 1][0], dp[i - 1][1] + arr[i] }
 *          可以      删除 i      或者从 0～i-1 之间挑一个删除
 */
class Solution {
 public:
  int maximumSum(vector<int>& arr) {
    vector<vector<int>> dp(arr.size(), vector<int>(2));
    int res = arr[0];
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      // 不删除
      dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
      // 删除 i，或从 0～i-1 之间挑
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
      res = max(res, max(dp[i][0], dp[i][1]));
    }
    return res;
  }
};