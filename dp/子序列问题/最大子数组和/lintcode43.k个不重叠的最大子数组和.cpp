/**
 * https://www.lintcode.com/problem/43/solution/19346
 * 双 DP
 * 
 * 局部 local[i][j] 为 nums 的前 i 个元素被分成 j 个不重叠子数组时的最大值（必须选取元素nums[i]）
 * 全局 global[i][j] 为 nums 的前 i 个元素被分成 j 个不重叠子数组时的最大值（不一定选取元素nums[i]）
 * 由局部情况（必定包含）推导出全局情况（不一定包含）
 * 
 * 则 i<j 时不可能存在可行解，且边界值为 i==j 时，每个元素各自为一组。
 * 所以我们从边界值往回递推（j从k递推回1），状态转移方程为（此时i >= j）：
 * 1. 边界 i == j 时:
 *    local[i][j] = local[i-1][j-1] + nums[i]
 *    global[i][j] = global[i-1][j-1] + nums[i]
 * 2. i != j 时:
 * 2.1 局部，对于第 i 个元素可以选择自己加入第 j-1 组（local[i-1][j]）
 *                  还是自己成为独立第 j 组（global[i-1][j-1]）
 * 则 local[i][j] = max(local[i-1][j], global[i-1][j-1]) + nums[i] 
 * 2.2 全局，第 i 个元素可以被选用 local[i][j]
 *              也可以不不选用 global[i-1][j]
 * 则 global[i][j] = max(global[i-1][j], local[i][j])
 */
class Solution {
 public:
  /**
   * @param nums: A list of integers
   * @param k: An integer denote to find k non-overlapping subarrays
   * @return: An integer denote the sum of max k non-overlapping subarrays
   */
  int maxSubArray(vector<int> &nums, int k) {
    int n = nums.size();
    if (n < k) {
      return 0;
    }
    int local[n + 3][k + 3] = {0}, global[n + 3][k + 3] = {0};
    for (int i = 1; i <= n; i++) {
      // 从边界值往前递推
      for (int j = min(i, k); j > 0; j--) {
        if (i == j) {
          local[i][j] = local[i - 1][j - 1] + nums[i - 1];
          global[i][j] = global[i - 1][j - 1] + nums[i - 1];
        } else {
          // local[i-1][j]表示nums[i]加入上一个子数组成为一部分
          // global[i-1][j-1]表示nums[i]重新开始一个新的子数组
          local[i][j] =
              max(local[i - 1][j], global[i - 1][j - 1]) + nums[i - 1];
          global[i][j] = max(global[i - 1][j], local[i][j]);
        }
      }
    }
    return global[n][k];
  }
};