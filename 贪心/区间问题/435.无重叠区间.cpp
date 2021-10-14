
/**
 * https://leetcode-cn.com/problems/non-overlapping-intervals/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-3/tan-xin-suan-fa-zhi-qu-jian-tiao-du-wen-ti
 * 区间选择问题
 */ 
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // 将区间按终点升序排序
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int res = 0;
    int end = INT_MIN;
    for (auto interval : intervals) { // 遍历所有区间，贪心选择最早结束的，即终点最小的
      if (interval[0] >= end) { // 左边界不能与当前选中的区间重叠，边界重叠不算区间重叠
        res++;
        end = interval[1];
      }
    }
    return intervals.size() - res;
  }
};