/**
 * https://leetcode-cn.com/problems/repeated-substring-pattern/
 * 暴力法：
 * 找到每一个和 s[0] 相等的位置 r，判断字符串是否以 s[0,r) 重复
 */
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int len = s.size();
    int r = 1;
    while (r < len) {
      // 找到每一个和 s[0] 相等的位置 r
      if (s[0] == s[r] && doCharge(s, r)) {
        return true;
      }
      r++;
    }
    return false;
  }
  // 判断字符串是否以 s[0,r) 重复
  bool doCharge(string &s, int r) {
    int len = s.size();
    int l = 0;
    int repeat = r - l;
    while (r < len) {
      if (s[l] != s[r]) return false;

      r++;
      l++;
    }

    return !(l % repeat);
  }
};

/**
 * s = [0...i)+[i...n)
 * 如果以 [0...i) 重复，则 s == [i...n) + [0...i)
 */
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    for (int i = 1; i <= s.size() / 2; i++) {
      string tmp = s.substr(i) + s.substr(0, i);
      if (tmp == s) {
        return true;
      }
    }
    return false;
  }
};

/**
 * https://leetcode-cn.com/problems/repeated-substring-pattern/solution/jian-dan-ming-liao-guan-yu-javaliang-xing-dai-ma-s/
 */
class Solution1 {
 public:
  bool repeatedSubstringPattern(string s) {
    auto ss = s + s;
    return ss.substr(1, ss.size() - 2).find(s) != string::npos;
  }
};