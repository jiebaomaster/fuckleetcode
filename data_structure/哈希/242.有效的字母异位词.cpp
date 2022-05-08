/**
 * https://leetcode-cn.com/problems/valid-anagram/
 */
class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> times;
    for (auto c : s) {
      times[c]++;
    }
    for (auto c : t) {
      times[c]--;
    }
    for (auto [c, t] : times) {
      if (t != 0) return false;
    }
    return true;
  }
};