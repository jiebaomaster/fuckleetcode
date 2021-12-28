/**
 * https://leetcode-cn.com/problems/binary-watch/
 * 组合问题，从所有 10 个灯中选择 turnedOn 个点亮，输出此时的时间，需要注意时间是否合法
 * dfs 求出所有选择方案
 */
class Solution {
 public:
  vector<string> res;
  vector<string> readBinaryWatch(int turnedOn) {
    vector<int> track; // 记录选中灯的索引
    dfs(track, turnedOn, 0);
    return res;
  }

  // 判断手表的每一位是否被选中
  void dfs(vector<int> track, int turnedOn, int index) {
    if (index == 10) {
      if (turnedOn == 0) {
        getTime(track);
      }
      return;
    }

    if (turnedOn > 0) { // 剪枝，只能选中 turnedOn 个
      track.push_back(index);
      dfs(track, turnedOn - 1, index + 1);
      track.pop_back();
    }

    dfs(track, turnedOn, index + 1);
  }

  // 由选中列表拼接出时间
  void getTime(vector<int> track) {
    int nums[] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    string time; // 时间字符串
    int hours = 0; // 小时数
    int mins = 0; // 分钟数
    for (int i = 0; i < track.size(); i++) {
      if (track[i] < 4) { // 前 4 个灯为小时数
        hours += nums[track[i]];
      } else {
        mins += nums[track[i]];
      }
    }
    if (hours < 12 && mins <= 59) { // 判断时间合法性
      time = to_string(hours);
      time += ":";
      if (mins == 0 || mins < 10) { // 分钟数需要补 0
        time += "0";
      }
      time += to_string(mins);

      res.push_back(time);
    }
  }
};