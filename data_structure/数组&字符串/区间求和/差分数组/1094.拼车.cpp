/**
 * https://leetcode.cn/problems/car-pooling/
 * 将行驶的路程看作总数组，乘客的上下车位置为一个区间，乘客数为区间中元素的值
 * 则每批乘客的上下次是一次区间更新，最终可得总数组中每个距离的乘客数，
 * 题目要求乘客数不能大于 capacity
 * 区间更新，单点查询，差分数组
 */
class Solution {
 public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    int far = 0;
    for (auto &t : trips) {
      far = max(far, t[2]);
    }
    vector<int> diff(far);

    for (auto &t : trips) {
      diff[t[1]] += t[0];
      if (t[2] < far) {
        diff[t[2]] -= t[0];
      }
    }

    int pre = 0;
    for (int i = 0; i < far; i++) {
      pre += diff[i];
      if (pre > capacity) {
        return false;
      }
    }
    return true;
  }
};