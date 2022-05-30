/**
 * https://leetcode-cn.com/problems/corporate-flight-bookings/
 * https://labuladong.gitee.io/algo/2/18/23/
 * 差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减。
 * 定义差分数组 diff[i] = num[i] - num[i-1]
 * 则 num[i...j] + k = { diff[i] + k
 *                     { diff[j+1] - k
 * 这样修改数组中的部分元素的时间复杂度降为 O(1)
 */
class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n);
    for (auto& booking : bookings) {
      diff[booking[0] - 1] += booking[2];
      if (booking[1] < n) diff[booking[1]] -= booking[2];
    }

    // 通过差分数组还原源数组
    for (int i = 1; i < diff.size(); i++) {
      diff[i] = diff[i - 1] + diff[i];
    }
    return diff;
  }
};