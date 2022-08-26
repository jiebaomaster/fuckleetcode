/**
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-2/bei-bao-zi-ji
 * 子集划分问题，我们可以先对集合求和，得出 sum，从而把问题转化为下列背包问题：
 * 给一个可装载重量为 sum / 2 的背包和 N 个物品，每个物品的重量为 nums[i]。现在让你装物品，是否存在一种装法，能够恰好将背包装满
 * dp[i][j] 表示对于前 i 个物品，是否存在一种装法，恰好装入容量为 j 的背包中
 * 对于每个物品 nums[i]，只有装入和不装入两种状态
 * 1. 如果不把第 i 个物品装入背包，那么是否能够恰好装满背包，
 *      取决于前面 i-1 个物品能否装满容量为 j 的背包，即 dp[i-1][j]
 * 2. 如果把第 i 个物品装入背包，那么是否能够恰好装满背包，
 *      取决于前面 i-1 个物品能否装满容量为 j-nums[i] 的背包，即 dp[i-1][j-nums[i]]。
 * 3. 当背包剩余空间不能装下第 i 个物品时，只能选择不装入物品 i 的情况
 */
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false; // 奇数肯定不能划分成等和的两份
    sum /= 2;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1));
    // 要装满一个空间为 0 的背包，只要什么都不装就可以了
    for (int i = 0; i <= nums.size(); i++) dp[i][0] = true;
    // 当没有物品可选择的时候，肯定没办法装满背包
    for (int j = 1; j <= sum; j++) dp[0][j] = false;

    for (int i = 1; i <= nums.size(); i++) {
      for (int j = 1; j <= sum; j++) {
        if (j < nums[i - 1]) // 背包的剩余空间太小，当前物品不能装入
          dp[i][j] = dp[i - 1][j];
        else // 当前物品可以装入也可以不装入，只要有一个满足即可
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      }
    }
    return dp[nums.size()][sum];
  }
};

// 状态压缩
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    sum /= 2;
    int n = nums.size();
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = sum; j > 0; j--) {
        if (!dp[j] && j >= nums[i - 1]) {
          dp[j] = dp[j - nums[i - 1]];
        }
      }
    }
    return dp[sum];
  }
};