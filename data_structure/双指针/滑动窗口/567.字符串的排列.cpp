/**
 * 判断是否存在字符串 s1 的排列之一是 s2 的 子串
 * 固定滑动窗口，寻找排列子串
 * https://leetcode-cn.com/problems/permutation-in-string/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/hua-dong-chuang-kou-ji-qiao-jin-jie#er-zi-fu-chuan-pai-lie
 */
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need,  // 目标字符串中每种字符需求的数量
        window;  // 滑动窗口中各 need 字符的数量，不记录无关字符
    for (const auto c : s1) need[c]++;  // 用目标字符串初始化 need

    int valid = 0;               // 窗口中有几个字符满足需求了
    int left = 0, right = 0;     // 滑动窗口 [left, right)
    while (right < s2.size()) {  // 遍历整个字符串
      char c = s2[right++];      // 窗口向右滑动
      if (need.count(c)) {       // 当前字符是需求字符，更新 window
        window[c]++;
        // 这次滑动使窗口中有一个字符刚好满足需求，更新满足需求的字符数量
        if (window[c] == need[c]) valid++;
      }

      // 滑动窗口的大小是固定的，窗口达到 s1 的大小后，每次向前滑动一格
      if (right - left == s1.size()) {
        if (valid == need.size()) return true;
        
        char c = s2[left++];
        if (need.count(c)) {  // 当前字符是需求字符，更新 window
          // 这次收缩使窗口中有一个字符刚好不满足需求，更新满足需求的字符数量
          if (window[c] == need[c]) valid--;
          window[c]--;
        }
      }
    }
    return false;
  }
};

/**
 * 方法二：非固定大小的窗口滑动
 */
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> times;
    for (char c : s1) {
      times[c]++;
    }

    int l = 0, r = 0;
    unordered_map<char, int> cur = times;
    int cnt = times.size(); // 还剩几个字符没有满足需求
    while (r < s2.size()) {
      if (cur.find(s2[r]) == cur.end()) {
        // 碰到非需求字符，重新开始
        r++;
        l = r;
        cur = times;
        cnt = times.size();
      } else {
        // s2[r] 是需求字符
        // 向右滑动一个
        cur[s2[r]]--;
        // 有一个字符满足要求了
        if (cur[s2[r]] == 0) {
          cnt--; // 更新
          if (cnt == 0) return true;
        }
        // s2[r] 出现的次数太多了，需要收缩左边界
        while (cur[s2[r]] == -1) {
          cur[s2[l]]++;
          // 收缩左边界导致有字符不满足需求
          if (cur[s2[l]] == 1) cnt++;
          l++;
        }
        r++;
      }
    }
    return false;
  }
};