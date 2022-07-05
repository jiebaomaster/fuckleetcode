/**
 * https://leetcode.cn/problems/minimum-number-of-days-to-make-m-bouquets/
 * 每束花要求使用相邻的 k 朵花，即分割连续数组，k 是影响函数关系的常量，而不是变量
 * 
 * 所需的花束数量越多，等待的时间就越长，分段单调增函数
 * 1. 当 所需的花束数量为 m 时，等待的时间存在一个范围，需要求得这个范围的最小值
 * 2. 当 等待的时间最长为 day 确定的时候，可以（贪心法）求得可以分出的花束数量
 * 
 *   cnt
 *   ^ 
 *   |       ---
 * m |    ---
 *   | ---   
 *   |----|--------> day
 *       res
 */
class Solution {
 public:
  // 等待不超过 day 天，且每束 k 朵的情况下，最多能分出几束
  int f(vector<int>& bloomDay, int day, int k) {
    int cnt = 0;
    int cur = 0;
    int maxDay = 0;
    for (const auto d : bloomDay) {
      if (maxDay < d) maxDay = d;
      if (maxDay > day) { // 这朵花开花时间太晚了，丢弃
        maxDay = 0;
        cur = 0;
      } else {
        cur++; // 归入当前花束
        if (cur == k) { // 花束达到要求
          cnt++;
          cur = 0;
          maxDay = 0;
        }
      }
    }
    return cnt;
  }
  int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() < m * k) return -1;

    int l = 0;
    int r = *max_element(bloomDay.begin(), bloomDay.end());

    while (l < r) {
      int mid = l + (r - l) / 2;
      if (f(bloomDay, mid, k) >= m) {
        r = mid;
      } else
        l = mid + 1;
    }
    return l;
  }
};