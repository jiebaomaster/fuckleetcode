/**
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/hua-dong-chuang-kou-ji-qiao-jin-jie#si-zui-chang-wu-zhong-fu-zi-chuan
 *
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;  // 滑动窗口中各字符的数量
    int maxsubstrlen = 0;             // 当前最长无重复子串长度
    int left = 0,
        right = 0;  // 滑动窗口 [left, right)，保持窗口中的子串是无重复的
    while (right < s.size()) {  // 遍历整个字符串
      char c = s[right++];      // 窗口向右滑动
      window[c]++;  // 每次滑动都把右边的元素加入窗口，更新窗口中各字符的数量

      // 如果这次滑动造成了窗口中某个字符的数量大于1了，左侧需要进行收缩，
      // 直到字符无重复，由于是字符 c 造成的重复，所有最后出窗口的也是 c
      while (window[c] > 1) {
        char d = s[left++];
        window[d]--;  // 有字符出窗口了，需要更新窗口中各字符的数量
      }

      // 每次有字符加入窗口，都要重新计算结果，当前子串长度为 right -left
      maxsubstrlen = max(maxsubstrlen, right - left);
    }
    return maxsubstrlen;
  }
};