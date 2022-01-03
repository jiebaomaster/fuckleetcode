/**
 * https://leetcode-cn.com/problems/target-sum/
 * https://programmercarl.com/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.html#_494-%E7%9B%AE%E6%A0%87%E5%92%8C
 * 要使表达式的运算结果为 target，则要将 nums 分为减数 right 
 * 和被减数 left 两堆，则有 left - right = target （1）
 * 又因为 left + right = sum （2）其中 sum 是已知的。
 * 由（1）+（2）有 left = (target + sum)/2
 * 问题被转化为 从 nums 中选取数，求和为 left 的组合的个数
 * 即求恰好装满为 left 的背包，有几种方法
 */
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target)) return 0;
    int left = target + sum;
    if (left % 2) return 0;
    left /= 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(left + 1));

    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); i++) { // 遍历物品
      // 当 nums[i]=0 时，dp[i][j] = dp[i-1][j]*2，加减 0 都一样
      // 当 nums[0]=0 时，第一列 dp[i][0] = dp[i-1][0]*2
      // 故 j 从 0 开始遍历，因为装入容量为 0 的背包的方法数也需要更新
      for (int j = 0; j <= left; j++) { // 遍历容量
        if (j < nums[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
      }
    }

    return dp[nums.size()][left];
  }
};