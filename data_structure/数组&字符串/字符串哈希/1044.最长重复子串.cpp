/**
 * https://leetcode.cn/problems/longest-duplicate-substring/
 * https://leetcode.cn/problems/longest-duplicate-substring/solution/wei-rao-li-lun-rabin-karp-er-fen-sou-suo-3c22/
 * 
 * 如果一个字符串中有可重复的子串，那么，我们可以从 (n-1) 的长度开始向下依次寻找每个长度是否存在重复的子串
 * 以重复子串的「最大长度」为轴具有「二段性」：
 * 小于等于最大长度方案均存在（考虑在最大长度方案上做删减）；
 * 不存在大于最大长度的重复子串
 */
class Solution {
 public:
  vector<unsigned long long> hash;
  vector<unsigned long long> power;
  const int PRIME = 1313131;
  string longestDupSubstring(string s) {
    int n = s.size();
    // 先把字符串哈希算好
    hash.resize(n + 1);
    power.resize(n + 1);
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
      hash[i] = hash[i - 1] * PRIME + s[i - 1];
      power[i] = power[i - 1] * PRIME;
    }

    // 二分查找重复子串的长度，找到最大的
    int l = 0;
    int r = n;
    string res;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (f(s, mid, res))
        l = mid;
      else
        r = mid - 1;
    }

    return res;
  }
  // 判断 s 中是否存在长度为 len 的重复子串
  bool f(string& s, int len, string& res) {
    unordered_set<unsigned long long> subs;
    for (int j = len; j <= s.size(); j++) {
      int i = j - len + 1;
      auto h = hash[j] - hash[i - 1] * power[j - i + 1];
      if (subs.count(h)) { // hash 出现过，即发现重复子串
        res = s.substr(i - 1, len);
        return true;
      }
      subs.insert(h);
    }
    return false;
  }
};