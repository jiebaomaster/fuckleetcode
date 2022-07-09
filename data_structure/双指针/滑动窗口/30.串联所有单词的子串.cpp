/**
 * https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
 * https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-6/
 * 
 * 方法一：双哈希表
 * words 总长度是固定的 len
 * 遍历 s，判断每个长度为 len 的子串 sub 是否和 words 构成的串相等
 * 因为 words 中每个元素的长度是相等的 step，将 sub 按 step 长度划分出一系列子串
 * 可以构成一个新的 字符串 表
 * 只要判断这个新的字符串表是否和 words 相等即可，即判断哈希表是否相等
 * 
 */
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> need;
    for (auto& s : words) need[s]++;
    vector<int> res;
    int step = words[0].size();
    int sublen = words.size() * step;
    for (int i = 0; i < s.size() - sublen + 1; i++) {
      auto cur = need;
      bool got = true;
      // 判断哈希表相等性
      for (int j = i; j < i + sublen; j += step) {
        auto sub = s.substr(j, step);
        // 遇到一个不存在的字符串，或者数量过多，则不相等
        if (cur.find(sub) == cur.end() || cur[sub] == 0) {
          got = false;
          break;
        }
        cur[sub]--;
      }
      if (got) res.push_back(i);
    }

    return res;
  }
};

/**
 * 方法二：滑动窗口
 */