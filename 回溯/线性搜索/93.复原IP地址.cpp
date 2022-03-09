/**
 * https://leetcode-cn.com/problems/restore-ip-addresses/
 * 方法一：基于选择集的 dfs
 */
class Solution {
 public:
  vector<string> res;
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4 || s.size() > 12) // ip 地址长度有要求
      return res;
    string tracking;
    dfs(tracking, s, 0, 0);
    return res;
  }
  /**
   * 对每个字符 s[index] 判断是否要在其之后进行分割
   * 
   * @param tracking 当前分割构成的字符串
   * @param s 原字符串
   * @param index 当前判断的字符在原字符串中的索引
   * @param cnt 已进行的分割次数
   */
  void dfs(string &tracking, string &s, int index, int cnt) {
    if (index == s.size()) {
      if (cnt == 3 && check(tracking)) res.push_back(tracking);

      return;
    }

    tracking.push_back(s[index]);

    // 分割 "." 小于 3 次，且 最后一位字符后不能分割
    if (cnt < 3 && index < s.size() - 1) {
      tracking.push_back('.');
      dfs(tracking, s, index + 1, cnt + 1);
      tracking.pop_back();
    }

    dfs(tracking, s, index + 1, cnt);

    tracking.pop_back();
  }
  // 判断分割后的字符串是否合法
  bool check(string &s) {
    int slow = 0;
    for (int fast = 1; fast <= s.size(); fast++) {
      if (fast == s.size() || s[fast] == '.') {
        // 判断 [slow, fast) 是否合法
        if (fast - slow > 1 && s[slow] == '0')  // 前导 0 不合法
          return false;
        if (fast - slow > 3)  // 大于三位数不合法
          return false;
        // 求值
        int i = fast - 1;
        int val = 0;
        int t = 1;
        while (slow <= i) {
          val += t * (s[i--] - '0');
          t *= 10;
        }
        if (val > 255) return false;
        slow = fast + 1;
      }
    }
    return true;
  }
};