/**
 * https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 */
class Solution {
 public:
  char firstUniqChar(string s) {
    unordered_map<char, int> times;
    for (char c : s) {
      times[c]++;
    }
    for (char c : s) {
      if (times[c] == 1) {
        return c;
      }
    }
    return ' ';
  }
};