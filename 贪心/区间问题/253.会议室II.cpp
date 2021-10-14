/**
 * https://labuladong.gitee.io/algo/3/28/98/
 * https://leetcode-cn.com/problems/meeting-rooms-ii/
 */
class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> start(intervals.size());
    vector<int> end(intervals.size());
    // 分开考虑起点和终点
    for (int i = 0; i < intervals.size(); i++) {
      start[i] = intervals[i][0];
      end[i] = intervals[i][1];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int res = 0, count = 0;
    /**
     * 把起点和终点统一投影到时间轴中，起点< ,终点>
     * 时间轴：----<-->--<<->>---<--->--
     * 遍历这个时间轴，遇到起点就+1，遇到终点就-1，则最大计数值就是重叠数量
     * 遍历时间轴可以转化为遍历时间点
     */
    while (i < intervals.size() && j < intervals.size()) {
      if (start[i] < end[j]) { // 先遇到起点
        count++;
        i++;
      } else { // 先遇到终点
        count--;
        j++;
      }
      res = max(res, count);
    }
    return res;
  }
};