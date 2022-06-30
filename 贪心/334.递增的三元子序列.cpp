/**
 * https://leetcode.cn/problems/increasing-triplet-subsequence/
 * 递增子序列问题可以用dp 解决，类似第 300 题，但这里会超时
 *
 */
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX; // 最小的数
    int b = INT_MAX; // a 之后，第二小的数
    for (int n : nums) {
      if (n <= a) { // 更新 a
        a = n;
      } else if (n <= b) { // 比 a 大，比 b 小，更新 b
        b = n;
      } else // 找到比 b 大的，即构成三元组 a b n
        return true;
    }
    return false;
  }
};