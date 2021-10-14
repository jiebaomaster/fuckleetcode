/**
 * https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-3/tan-xin-suan-fa-zhi-qu-jian-tiao-du-wen-ti#san-ying-yong-ju-li
 * 区间选点问题，覆盖所有区间最少需要几个点，即问有几个不重叠区间
 */
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // 将区间按右边界升序排序
    sort(points.begin(), points.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int res = 1; // 第一个区间肯定被选到
    int end = points[0][1];
    for (int i = 1; i < points.size(); i++) {  // 遍历所有区间，贪心选择最早结束的
      if (points[i][0] > end) {  // 左边界不能与当前选中的区间重叠
        res++;
        end = points[i][1];
      }
    }
    return res;
  }
};