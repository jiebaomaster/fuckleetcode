/**
 * https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/er-fen-yun-yong#li-ti-er-yun-song-huo-wu 
 */
class Solution {
 public:
  // 计算 船的运载能力为 capacity 时，需要多少天运完
  int f(vector<int>& weights, int capacity) {
    int days = 0, curr = 0;
    for (const auto w : weights) {
      if (curr + w < capacity) {
        curr += w;
      } else if (curr + w == capacity) {
        curr = 0;
        days++;
      } else {
        curr = w;
        days++;
      }
    }
    if (curr != 0) days++;
    return days;
  }

  int shipWithinDays(vector<int>& weights, int days) {
        // 运送的货物不会超过船舱容量
    int left = *max_element(weights.begin(), weights.end()),
        // 最快一天把所有货物运完
        right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
      int mid = left + (right - left) / 2;
      // 以当前速度满足时间要求，尝试更小的速度
      if (f(weights, mid) <= days) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};