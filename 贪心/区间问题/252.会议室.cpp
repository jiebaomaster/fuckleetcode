/**
 * https://leetcode.cn/problems/meeting-rooms/
 * 判断区间是否存在重合
 */
class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& lhs, vector<int>& rhs) {
           if (lhs[0] != rhs[0])
             return lhs[0] < rhs[0];
           else
             return lhs[1] < lhs[1];
         });

    for (int i = 0; i < (int)intervals.size() - 1; i++) {
      if (intervals[i][1] > intervals[i + 1][0]) return false;
    }
    return true;
  }
};