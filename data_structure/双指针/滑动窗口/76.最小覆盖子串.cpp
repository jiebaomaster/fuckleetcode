/**
 * https://leetcode-cn.com/problems/minimum-window-substring/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/hua-dong-chuang-kou-ji-qiao-jin-jie#yi-zui-xiao-fu-gai-zi-chuan
 */
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need,  // 目标字符串中每种字符需求的数量
        window;  // 滑动窗口中各 need 字符的数量，不记录无关字符
    for (const auto c : t) need[c]++;  // 用目标字符串初始化 need

    int start = 0, len = INT_MAX;  // 结果子串的起始和长度
    int valid = 0;                 // 窗口中有几个字符满足需求了
    int left = 0, right = 0;       // 滑动窗口 [left, right)

    while (right < s.size()) {  // 遍历整个字符串
      char c = s[right++];      // 窗口向右滑动
      if (need.count(c)) {      // 当前字符是需求字符，更新 window
        window[c]++;
        // 这次滑动使窗口中有一个字符刚好满足需求，更新满足需求的字符数量
        if (need[c] == window[c]) valid++;
      }

      // 滑动窗口中的字符满足全部需求，左边收缩，直到不满足为止
      while (valid == need.size()) {
        if (len > right - left) {  // 满足需求，更新最小子串
          start = left;
          len = right - left;
        }
        char c = s[left++];   // 左边收缩
        if (need.count(c)) {  // 当前字符是需求字符，更新 window
          // 这次收缩使窗口中有一个字符刚好不满足需求，更新满足需求的字符数量
          if (need[c] == window[c]) valid--;
          window[c]--;
        }
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
