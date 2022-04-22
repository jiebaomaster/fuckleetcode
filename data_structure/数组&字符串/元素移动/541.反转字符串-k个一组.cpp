/**
 * https://leetcode-cn.com/problems/reverse-string-ii/
 * https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
 */
class Solution {
 public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      // 1. 每隔 2k 个字符的前 k 个字符进行反转
      // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
      if (i + k < s.size()) {
        doReverse(s, i, i + k - 1);
        continue;
      }
      // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
      doReverse(s, i, s.size() - 1);
    }
    return s;
  }
  // 翻转字符串区域 s[l...r]
  void doReverse(string &s, int l, int r) {
    while (l < r) {
      auto tmp = s[l];
      s[l] = s[r];
      s[r] = tmp;
      l++;
      r--;
    }
  }
};