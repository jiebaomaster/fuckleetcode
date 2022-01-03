/**
 * 
 * https://leetcode-cn.com/problems/combination-sum-iv/solution/shu-ju-jie-gou-he-suan-fa-dong-tai-gui-h-jain/
 * 
 * 为求组合成 target 共有几种方法，
 * 一般的思路是先遍历 num[]，分类讨论是否选中 num[i]，如果把第 i 个物品装入背包，
 * 那么恰好装满背包的方法数，取决于使用前面 i 个物品（完全背包）装满容量为 j-num[i]
 * 的背包的方法数，即 dp[i][j-coins[i]]。
 * 实际上经典思想所求的是组合数
 * 
 * 而本题的结果集中考虑了元素之间的顺序，5=2+2+1 和 5=2+1+2 是两种结果
 * 考虑把第 i 个物品装入背包时 dp[i][j] 不再等于 dp[i][j-num[i]]，因为新加入的 num[i]
 * 可以插入 dp[i][j-coins[i]] 的结果集的不同位置中产生更多的排列
 * 例如，考虑 num[]={1,2,3}，target=5，易知 dp[3][2] 的结果集为 {1,1} {2}，共 2 个
 * 求 dp[3][5]，当选中 num[2]=3 时，结果集除了对应 dp[3][2] 的 {1,1,3} {2,3}
 * 还有 {3,1,1} {1,3,1} {3,2} 共 5 个
 * 
 * 完全背包求排列数，可以使用 70.爬楼梯 的思想：
 * 定义 dp[i] 表示和为 i 的组合个数，那么这个 dp[i] 怎么求呢。
 * 例如，求 dp[5] 就是要找和为 5 的组合：
 *  可以用和为 1 的组合（dp[1]）最后位置插入 4
 *  或者用和为 2 的组合（dp[2]）最后位置插入 3
 *  或者用和为 3 的组合（dp[3]）最后位置插入 2
 *  或者用和为 4 的组合（dp[4]）最后位置插入 1
 * 所以 dp[5] = dp[1] + dp[2] + dp[3] + dp[4];
 * 但这里会有个问题，假如数组 nums 中没有 2，就没法用和为 3 的组合加上 2 了，
 * 因为根本就没有 2 可选。所以我们能选的数字其实就是数组 nums 中的元素。
 * 所以，求 dp[i]
 *  可以用和为 i-nums[0] 的组合（dp[i-nums[0]]）最后位置插入 nums[0]
 *  或者用和为 i-nums[1] 的组合（dp[i-nums[1]]）最后位置插入 nums[1]
 *  或者用和为 i-nums[2] 的组合（dp[i-nums[2]]）最后位置插入 nums[2]
 *  ......
 * 所以 dp[i] = dp[i-nums[0]] + dp[i-nums[1]] + ...
 */
class Solution {
 public:
  int res = 0;
  int combinationSum4(vector<int>& nums, int target) {
    // dp[i] 表示总和为 i 的组合数
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) { // 遍历容量
      for (int j = 0; j < nums.size(); j++) { // 遍历物品
        // 选择数组 nums 中每一个元素，注意不能大于 i
        // INT_MAX > dp[i - nums[j]] + dp[i] 防止结果大于 int
        if (nums[j] <= i && INT_MAX - dp[i] > dp[i - nums[j]]) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    return dp[target];
  }
};