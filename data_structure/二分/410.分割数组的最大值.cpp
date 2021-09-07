/**
 * https://leetcode-cn.com/problems/split-array-largest-sum/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/er-fen-fen-ge-zi-shu-zu
 */
class Solution {
 public:
  // 易得当 sum_max 增大时，需要分的组数减小，即单调函数关系
  // 求 当和的最大值不超过 sum_max 时，需要分几组。
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