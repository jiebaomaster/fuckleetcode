/**
 * https://leetcode-cn.com/problems/remove-covered-intervals/
 * https://labuladong.gitee.io/algo/4/33/125/
 *
 */
class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) {
           if (a[0] == b[0]) return a[1] > b[1];
           return a[0] < b[0];
         });

    int res = 0;
    // 区间 [left, right]，与当前遍历到的区间比较
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      /**
       * [----]
       *     [----] 
       * [--------] 交叉，合并
       * 连续区间合并后更大的区间可以覆盖其他区间
       */
      if (left < intervals[i][0] && right < intervals[i][1]) {
        right = intervals[i][1];
        continue;
      }
      /**
       * [-------]
       *    [---]
       * [-------] 覆盖，删除
       * 一开始按起点升序终点降序排序，保证了被覆盖到区间总是在后面出现
       */
      if (left <= intervals[i][0] && right >= intervals[i][1]) {
        res++;
        continue;
      }
      /**
       * [---]
       *       [---]
       *       [---] 不相交，转移
       */
      if (right < intervals[i][0]) {
        left = intervals[i][0];
        right = intervals[i][1];
      }
    }

    return intervals.size() - res;
  }
};