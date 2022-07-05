/**
 * @brief
 * https://leetcode-cn.com/problems/koko-eating-bananas/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/er-fen-yun-yong#li-ti-yi-ke-ke-chi-xiang-jiao
 */
class Solution {
 public:
  // 求 每小时吃 v 根时，吃完所需的时间
  int f(vector<int>& piles, int v) {
    int sum = 0;
    for (const auto e : piles)  // 遍历累加吃完每一堆所需时间
      sum += e % v ? (e / v + 1) : (e / v);
    return sum;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    // 最小和最大速度，最大速度为香蕉堆的最大值，比这个大的速度效果都一样
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
      int mid = left + (right - left) / 2;
      // 以当前速度吃香蕉需要的时间满足要求，可以尝试更小的速度
      if (f(piles, mid) <= h) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};