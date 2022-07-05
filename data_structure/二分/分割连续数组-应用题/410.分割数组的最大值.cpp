/**
 * https://leetcode-cn.com/problems/split-array-largest-sum/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/er-fen-fen-ge-zi-shu-zu
 * https://leetcode.cn/problems/split-array-largest-sum/solution/er-fen-cha-zhao-by-liweiwei1419-4/
 * 
 * 求最大值的最小值（最小值的最大），必定用二分
 * 其中第一层最大值由题目条件确定的函数保证，第二层最小值由二分法求得
 * 
 * 分割连续数组
 * 分割的次数越多，子数组和的最大值越小，分段单调减函数。
 * 1. 当 分割次数为 m 时，子数组和的最大值存在一个范围，需要求得这个范围的最小值
 * 2. 当 子数组和的最大值 sum_max 确定的时候，可以（贪心法）求得需要分成几组
 * 
 *  cnt
 *   ^ 
 *   | ---
 * m |    ---
 *   |        ---
 *   |----|--------> sum_max
 *       res
 */
class Solution {
 public:
  // 易得当 sum_max 增大时，需要分的组数减小，即单调函数关系
  // 贪心计算 当子数组和的最大值为 sum_max 时，需要分几组。
  int f(vector<int>& nums, int sum_max) {
    int count = 1,  // 默认最后一组
        cur = 0;
    for (const auto num : nums) {  // 贪心策略，没达到最大值之前，尽量分配
      cur += num;
      if (cur > sum_max) {  // 达到最大值了，计算下一组
        cur = num;
        count++;
      }
    }
    return count;
  }
  int splitArray(vector<int>& nums, int m) {
    int left = *max_element(nums.begin(), nums.end()),
        right = accumulate(nums.begin(), nums.end(), 0);
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (f(nums, mid) <= m)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};