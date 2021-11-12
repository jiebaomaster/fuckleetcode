/**
 * https://leetcode-cn.com/problems/house-robber/
 * https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw
 * https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-leetcode-solution/
 * 
 * 状态：
 *  dp[i] 表示从 [0~i] 打劫可获得的最大金钱数
 * 选择：
 *  对于每个 i，可以选择打劫或者不打劫。如果要打劫，则必须 i-1 不打劫，此时 dp[i-1]=dp[i-2]
 *  dp[i] = max{ dp[i-1], dp[i-2]+nums[i] }
 *        = max{ 打劫      不打劫}
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[n - 1];
  }
};