/**
 * https://leetcode.cn/problems/xiao-zhang-shua-ti-ji-hua/
 * 类似第 410 题，本质还是分割连续数组，区别只在于函数关系
 * 花费的天数越多，做题时间最多的一天耗时就越小
 * 1. 当 花费的天数为 m 时，做题时间最多的一天耗时存在一个范围，需要求得这个范围的最小值
 * 2. 当 做题时间最多的一天耗时 hours 确定的时候，可以（贪心法）求得需要花费几天
 */
class Solution {
 public:
  // 贪心，计算每天最多时间为 hours 时，需要几天完成计划
  int f(vector<int>& time, int hours) {
    int cnt = 1;
    int cur = 0;
    bool jmped = false;
    int maxT = 0;
    for (int i = 0; i < time.size(); i++) {
      if (time[i] > maxT) maxT = time[i]; // 维护当天最大值，跳过最大值是最划算的
      cur += time[i];
      if (cur > hours) {
        if (!jmped) { // 当天可以进行一次场外援助
          cur -= maxT; // 减去场外援助时间
          jmped = true;
        } else { // 场外援助用完了，这一题必须放到第二天做了
          cnt++; 
          maxT = 0;
          jmped = false;
          cur = 0;
          i--; // 刚刚这题还没做，回去再做
        }
      }
    }
    return cnt;
  }
  int minTime(vector<int>& time, int m) {
    int l = 0;
    int r = accumulate(time.begin(), time.end(), 0);
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (f(time, mid) <= m) {
        r = mid;
      } else
        l = mid + 1;
    }
    return l;
  }
};