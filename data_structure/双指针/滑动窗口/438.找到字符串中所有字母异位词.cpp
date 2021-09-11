/**
 * 字符串 p 的排列是 s 的子串，找到所有这种情况下在 s 的索引
 * 思路和 567 一样，固定滑动窗口寻找排列子串
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/hua-dong-chuang-kou-ji-qiao-jin-jie#san-zhao-suo-you-zi-mu-yi-wei-ci
 */
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    unordered_map<char, int> need,  // 目标字符串中每种字符需求的数量
        window;  // 滑动窗口中各 need 字符的数量，不记录无关字符
    for (const auto c : p) need[c]++;  // 用目标字符串初始化 need

    int valid = 0;              // 窗口中有几个字符满足需求了
    int left = 0, right = 0;    // 滑动窗口 [left, right)
    while (right < s.size()) {  // 遍历整个字符串
      char c = s[right++];      // 窗口向右滑动
      if (need.count(c)) {      // 当前字符是需求字符，更新 window
        window[c]++;
        // 这次滑动使窗口中有一个字符刚好满足需求，更新满足需求的字符数量
        if (window[c] == need[c]) valid++;
      }

      // 滑动窗口的大小是固定的，窗口达到 s1 的大小后，每次向前滑动一格
      if (right - left == p.size()) {
        if (valid == need.size()) res.push_back(left);

        char c = s[left++];
        if (need.count(c)) {  // 当前字符是需求字符，更新 window
          // 这次收缩使窗口中有一个字符刚好不满足需求，更新满足需求的字符数量
          if (window[c] == need[c]) valid--;
          window[c]--;
        }
      }
    }
    return res;
  }
};