/**
 * https://leetcode-cn.com/problems/decode-ways/
 * https://leetcode-cn.com/problems/decode-ways/solution/jie-ma-fang-fa-by-leetcode-solution-p8np/
 * 约束更加复杂的走楼梯
 */
class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
      if (s[i - 1] == '0') { // 0 只能和前面的 1/2 组合解码
        if (s[i - 2] == '1' || s[i - 2] == '2') {
          dp[i] = dp[i - 2];
        }
      } else { // 非 0 可以自我解码 或者 和前一位组合解码
        dp[i] = dp[i - 1];
        if (s[i - 2] != '0') { // 前一位是 0 的，不可组合解码
          int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
          if (t <= 26) dp[i] += dp[i - 2];
        }
      }
      // 有一处不能解码则整体都不能解码
      if (dp[i] == 0) return 0;
    }
    return dp[s.size()];
  }
};