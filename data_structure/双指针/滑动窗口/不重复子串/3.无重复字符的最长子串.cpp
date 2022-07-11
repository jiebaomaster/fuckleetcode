/**
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/hua-dong-chuang-kou-ji-qiao-jin-jie#si-zui-chang-wu-zhong-fu-zi-chuan
 * 
 * 方法一：滑动窗口
 * 右直走，左按条件滑动，实际上会遍历字符串两次
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

/**
 * 方法二：记录字符上一次出现的位置，直接跳转，避免左指针滑动，遍历字符串一次
 * 1. abcaab
 *       | r 指向第二个 a，l 应该跳转到 a 上一次出现的位置之后，即 l=1
 * 2. abcaab
 *        | r 指向第三个 a，l 应该跳转到 a 上一次出现的位置之后，即 l=4
 * 3. abcaab
 *         | r 指向第二个 b，b 上一次出现的位置 1 处，此时 l 已经为 4 了，
 *           已经跳过了 b 上一次出现的位置，所以 l 不用动
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0;
    vector<int> position(128, -1); // 初始化为 -1，处理最长不重复字符串在开头的情况
    int res = 0;
    while (r < s.size()) {
      l = max(l, position[s[r]] + 1); // 跳转到上一次出现的位置之后或保持不动
      position[s[r]] = r; // 更新上一次出现的位置
      r++;
      res = max(res, r - l);
    }
    return res;
  }
};