/**
 * https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * 在 arr 中找两个互不重叠的子数组 且它们的和都等于 target 。
 * 可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。
 * 
 * 这题最简单的方法是先用滑动窗口把所有和为 target 的窗口都找出来，
 * 然后再遍历所有窗口找两个不重合且长度和最小的
 * 
 * 滑动窗口 + 动态规划
 * https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/solution/1477-cji-hu-shuang-bai-de-dong-tai-gui-h-4pi5/
 * 可以借助动态规划的思想，在找窗口的过程中就算出结果，关键是记录已计算出的结果
 * 设 dp[r] 为到位置 r 为止，和为 target 的最短子数组长度
 * 若 [l,r] 符合条件 dp[r] = min{dp[r-1], r-l+1};
 * 若 [l,r] 不符合条件 dp[r] = dp[r-1]
 */
class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    vector<int> dp(arr.size() + 1);
    int l = 1, r = 1;
    int cur = 0;
    int ret = INT_MAX;
    dp[0] = 0x1f1f1f1f; // 一个较大值，表示不可构成 target
    while (r <= arr.size()) { // 滑动窗口找符合条件的子数组
      cur += arr[r - 1];

      while (cur > target) {
        cur -= arr[l - 1];
        l++;
      }
      if (cur == target) { // [l,r] 符合条件
        dp[r] = min(dp[r - 1], r - l + 1);
        // 当前选取的两个子数组为 [l,r] 和在 l 之前的最小子数组
        ret = min(ret, r - l + 1 + dp[l - 1]);
      } else { // [l,r] 不符合条件
        dp[r] = dp[r - 1];
      }
      r++;
    }
    return ret > arr.size() ? -1 : ret;
  }
};

/**
 * 本题还可推广到，在 arr 中找 K 个互不重叠的子数组 且它们的和都等于 target 。
 * 
 */