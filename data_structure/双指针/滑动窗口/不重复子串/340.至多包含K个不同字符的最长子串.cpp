/**
 * https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/
 * 给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。
 */
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> times; // 记录滑动窗口中每个字符出现的次数
    int l = 0, r = 0;
    int res = -1;
    while (r < s.size()) {
      times[s[r++]]++;
      // 滑动窗口包含太多字符了，从左边删去一些
      while (times.size() > k) {
        times[s[l]]--;
        if (times[s[l]] == 0) {
          times.erase(s[l]); // 删除不在滑动窗口中的字符
        }
        l++;
      }
      res = max(res, r - l);
    }
    return res;
  }
};