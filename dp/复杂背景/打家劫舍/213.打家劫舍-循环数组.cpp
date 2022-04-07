/**
 * https://leetcode-cn.com/problems/house-robber-ii/
 * https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw
 * https://leetcode-cn.com/problems/house-robber-ii/solution/da-jia-jie-she-ii-by-leetcode-solution-bwja/
 * 
 * 本题可以看作是198题的特殊情况，是一个循环数组，即首尾房间不能同时被抢
 * 首尾房间不能同时被抢，那么只可能有三种不同情况：要么都不被抢；要么第一间房子被抢最后一间不抢；要么最后一间房子被抢第一间不抢。
 * 最大值只可能出现在后两种情况中。如果共有 [0 ~ n] 个房间：
 *  1. 要保证第一间房子可以被抢，最后一间不抢，可以限定抢劫范围 [0 ~ n-1]
 *  2. 要保证最后一间可以房子被抢，第一间不抢，可以限定抢劫范围 [1 ~ n]
 * 最终求最大值即可 max{ rob[0 ~ n-1], rob[1 ~ n] }
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(do_rob(nums, 0, n - 2), do_rob(nums, 1, n - 1));
  };
  /**
   * @brief 打劫 [l,r] 范围内的房间
   * 
   * @param nums 
   * @param l 
   * @param r 
   * @return int 
   */
  int do_rob(vector<int>& nums, int l, int r) {
    int n = r - l + 1;
    if (n <= 0) return 0;
    if (n == 1) return nums[l];

    vector<int> dp(n);
    dp[0] = nums[l];
    dp[1] = max(nums[l], nums[l + 1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 2] + nums[l + i], dp[i - 1]);
    }

    return dp[n - 1];
  }
};