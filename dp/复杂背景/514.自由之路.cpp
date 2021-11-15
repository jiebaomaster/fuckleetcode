/**
 * https://leetcode-cn.com/problems/freedom-trail/
 * https://labuladong.gitee.io/algo/3/24/81/
 * 
 */
class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    unordered_map<char, vector<int>> char_times;
    // 统计环中每个字母出现的位置
    for (int i = 0; i < ring.size(); i++) char_times[ring[i]].push_back(i);
    // dp[i][j] 表示 当圆盘指针指向 ring[i] 时，输入字符串 key[j...] 所需的最少步数
    // base case dp[i][key.size()]=0
    vector<vector<int>> dp(ring.size(), vector<int>(key.size() + 1));

    // 遍历字符串，倒序 dp，因为子问题依赖额外的状态：当前圆环指针的位置，只能从后续的状态得知
    for (int j = key.size() - 1; j >= 0; j--) {
      for (int i = 0; i < ring.size(); i++) { // 遍历 ring 的启示位置
        int res = INT_MAX;
        for (int nextposition : char_times[key[j]]) { // 遍历圆环中所有可选的位置，求最小值
          // 1. 在环中从 i 走到 nextposition，选择顺时针转和逆时针转中代价最小的那种
          int delta = min(abs(i - nextposition),
                          abs((int)ring.size() - abs(i - nextposition)));
          // 2. 求使用环中当前位置 nextposition 的 key[j]，需要的步数，加 1 是因为按下按钮也算一步
          // 子问题是：使用圆环指针指向 nextposition 时，输入字符串 key[j+1...] 所需的最少步数
          res = min(res, dp[nextposition][j + 1] + delta + 1);
        }
        dp[i][j] = res;
      }
    }
    return dp[0][0];
  }
};