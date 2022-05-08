/**
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * 按单词为单位翻转字符串
 */
class Solution {
 public:
  string reverseWords(string s) {
    int l = 0, r = 0;
    while (r < s.size()) {
      if (s[r] == ' ') {
        doReverse(s, l, r - 1);
        l = r + 1;
      }
      r++;
    }
    doReverse(s, l, r - 1);
    return s;
  }
  void doReverse(string &s, int l, int r) {
    while (l < r) {
      swap(s[l++], s[r--]);
    }
  }
};