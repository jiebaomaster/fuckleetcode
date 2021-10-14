/**
 * https://leetcode-cn.com/problems/video-stitching/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-3/jian-shi-pin
 * 
 */
class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int time) {
    // 按起点升序，保证首先满足起点要求
    sort(clips.begin(), clips.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });

    if (clips[0][0] > 0) return -1;
    int res = 0;
    int curend = 0, nextend = 0;
    // clips[i][0] <= curend 保证了选择的区间是连续的
    for (int i = 0; i < clips.size() && clips[i][0] <= curend;) {
      // 贪心，选择起点小于上一个选中区间终点的 所有区间中终点最大的那个
      while (i < clips.size() && clips[i][0] <= curend) {
        nextend = max(nextend, clips[i][1]);
        i++;
      }

      res++;
      curend = nextend;
      // 当前终点大于指定时间了，说明已经满足要求
      if (curend >= time) return res;
    }

    return -1;
  }
};