/**
 * https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 * 每个字母对应最后一位或者最后两位，类似跳台阶
 */
class Solution {
 public:
  int translateNum(int num) {
    string s = to_string(num);
    int dp_i = 1, dp_i_1 = 1, dp_i_2 = 1;
    for (int i = 1; i < s.size(); i++) {
      dp_i = dp_i_1;
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '5')) 
        dp_i += dp_i_2;
      dp_i_2 = dp_i_1;
      dp_i_1 = dp_i;
    }
    return dp_i;
  }
};