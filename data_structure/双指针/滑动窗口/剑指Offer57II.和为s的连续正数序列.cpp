/**
 * https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 * 双指针维护一个窗口，根据窗口和 target 的关系移动左右边界
 */
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    int l = 1, r = 1;
    int sum = 1;
    vector<int> track;
    while (r < target) {
      if (sum == target) { // 找到一个
        int ll = l;
        while (ll <= r) {
          track.push_back(ll++);
        }
        res.push_back(track);
        track.clear();
        r++;
        sum += r;
      } else if (sum < target) { // 需要扩大，走右边
        r++;
        sum += r;
      } else { // 需要缩小，走左边
        sum -= l;
        l++;
      }
    }
    return res;
  }
};