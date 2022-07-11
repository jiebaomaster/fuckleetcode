/**
 * https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/
 */
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int l = 0, r = 0;
    int res = 0;
    int windowLen = 0;
    unordered_map<char, int> ctimes;
    while (r < s.size()) {
      ctimes[s[r]]++;
      if (ctimes[s[r]] == 1) {
        windowLen++;
      }
      while (windowLen > 2) {
        ctimes[s[l]]--;
        if (ctimes[s[l]] == 0) {
          windowLen--;
        }
        l++;
      }
      res = max(res, r - l + 1);
      r++;
    }
    return res;
  }
};