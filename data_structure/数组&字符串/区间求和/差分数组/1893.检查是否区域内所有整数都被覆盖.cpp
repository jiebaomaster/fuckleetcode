/**
 * @brief
 * 方法一：区间合并模拟
 */
class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    sort(ranges.begin(), ranges.end(), [](vector<int>& lhs, vector<int>& rhs) {
      if (lhs[0] != rhs[0]) {
        return lhs[0] < rhs[0];
      } else {
        return lhs[1] > rhs[1];
      }
    });

    if (ranges[0][0] > left) return false;

    int far = ranges[0][0];
    for (auto& r : ranges) {
      if (left < far && far < r[0] - 1) return false;
      far = max(far, r[1]);
      if (far >= right) return true;
    }
    return false;
  }
};

/**
 * 方法二：差分数组
 * https://leetcode.cn/problems/check-if-all-the-integers-in-a-range-are-covered/solution/yi-ti-san-jie-bao-li-you-hua-chai-fen-by-w7xv/
 * ranges 是已覆盖的区间，求[left,right]是否被覆盖
 * 可以由 ranges 构建出总的覆盖情况，覆盖过一次就加 1，区间更新
 * 最会还原出覆盖数组，查询 [left, right] 是否被覆盖，即其中不能出现 0
 */
class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> diff(52); // 
    for (auto& r : ranges) {
      diff[r[0]]++;
      diff[r[1] + 1]--;
    }
    vector<int> covered(52);
    for (int i = 1; i < 52; i++) covered[i] = diff[i] + covered[i - 1];

    for (int i = left; i <= right; i++) {
      if (covered[i] <= 0) return false;
    }
    return true;
  }
};