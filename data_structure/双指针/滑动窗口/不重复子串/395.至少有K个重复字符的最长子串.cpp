/**
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
 * 一个字符串 s 和一个整数 k，请你找出 s 中的最长子串，要求该子串中的每一字符出现次数都不少于 k
 * 
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/solution/xiang-jie-mei-ju-shuang-zhi-zhen-jie-fa-50ri1/
 * 方法一：分类滑动窗口
 * 不能直接用双指针，但是增加限制区间内不同字符的个数后，可以转换为第 340 题，就可以用滑动窗口做了
 * s 仅由小写英文字母组成，所以最终字符串中的字符数最多为 26 个
 * 对于 子串中包含的字符数为 size 的情况下，可以判断子串中每个字符的出现次数是否都不少于 k
 */
class Solution {
 public:
  int longestSubstring(string s, int k) {
    int res = 0;
    for (int size = 1; size <= 26; size++) {
      int times[26] = {0}; // 每种字符的出现次数
      int l = 0, r = 0;
      int cnt = 0; // 子串中的不同字符数
      int curk = 0; // 子串中满足条件（出现次数不少于 k）的字符数
      while (r < s.size()) {
        times[s[r] - 'a']++;
        if (times[s[r] - 'a'] == k) curk++;
        if (times[s[r] - 'a'] == 1) cnt++;
        r++;
        while (cnt > size) { // 根据子串中的字符种类数进行收缩
          times[s[l] - 'a']--;
          if (times[s[l] - 'a'] == 0) cnt--;
          if (times[s[l] - 'a'] == k - 1) curk--;

          l++;
        }
        // 当前子串 [l,r) 中的所有字符都满足条件（出现次数不少于 k）
        // 更新结果
        if (curk == size) res = max(res, r - l);
      }
    }
    return res;
  }
};

/**
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/solution/jie-ben-ti-bang-zhu-da-jia-li-jie-di-gui-obla/
 * 方法二：分治
 * 对于字符串 s，如果存在某个字符 ch，它的出现次数大于 0 且小于 k，则任何包含 ch 的子串
 * 都不可能满足要求。也就是说，我们将字符串按照 ch 切分成若干段，则满足要求的最长子串一定
 * 出现在某个被切分的段内，而不能跨越一个或多个段。
 */
class Solution {
 public:
  int longestSubstring(string s, int k) { return dc(s, 0, s.size(), k); }

  int dc(string &s, int l, int r, int k) {
    if (l >= r) return 0;

    // 统计每一个字符出现的次数
    unordered_map<char, int> times;
    for (int i = l; i < r; i++) {
      times[s[i]]++;
    }

    int res = -1;
    int start = l;
    // 以每一个不满足次数要求的字符为分界点
    // 将原字符串分为更小的子串，递归求这些子串中的最大值
    for (int i = l; i < r; i++) {
      if (times[s[i]] < k) {
        res = max(res, dc(s, start, i, k));
        start = i + 1;
      }
    }
    if (start != l) {
      res = max(res, dc(s, start, r, k));
    }
    return res == -1 ? r - l : res;
  }
};