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
 *        = max{ 不打劫    打劫}
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

    // 打印实际选择路径的代码
    // 由 max 进行的递推可以通过从后向前倒走 dp 数组输出选择路径
    // vector<int> path;
    // int i = n - 1;
    // while (i >= 2) { // 从后向前倒走 dp 数组
    //   if (dp[i - 2] + nums[i] > dp[i - 1]) {
    //     path.push_back(i); // 当前元素被选中
    //     i -= 2;
    //   } else {
    //     i -= 1;
    //   }
    // }
    // path.push_back(i); // 0 或 1 必被选中一个

    return dp[n - 1];
  }
};

/**
 * dp[i][1] 表示在第 i 号打劫时，可获得的最大收益，此时第 i-1 号不能打劫
 *          = dp[i - 1][0] + nums[i - 1]
 * dp[i][0] 表示在第 i 号不打劫时，可获得的最大收益，此时第 i-1 号随意
 *          = max(dp[i - 1][0], dp[i - 1][1])
 */       
class Solution1 {
 public:
  int rob(vector<int>& nums) {
    vector<vector<int>> dp(nums.size() + 1, vector<int>(2));
    for (int i = 1; i <= nums.size(); i++) {
      dp[i][1] = dp[i - 1][0] + nums[i - 1];
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    return max(dp[nums.size()][1], dp[nums.size()][0]);
  }
};