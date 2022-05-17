/**
 * https://leetcode.cn/problems/palindromic-substrings/
 * 统计回文子串的个数
 * 
 * 方法一：区间 dp，参考第 5 题
 */
class Solution {
 public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    int res = n;
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j] && (dp[i + 1][j - 1] || i + 1 == j)) {
          dp[i][j] = true;
          res++;
        }
      }
    }
    return res;
  }
};

/**
 * 方法二：双指针中心扩散
 * 空间复杂度为 O(1)
 */
class Solution {
 public:
  int countSubstrings(string s) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += extend(s, i, i); // [i] 开始扩散
      res += extend(s, i, i + 1); // [i,i+1] 开始扩散
    }
    return res;
  }

  // 计算以 [l,r] 为中心的回文数
  int extend(string &s, int l, int r) {
    int cnt = 0;
    while (l >= 0 && r < s.size()) {
      if (s[l--] != s[r++]) {
        break;
      } else { // 相等的左右端点，继续扩散
        cnt++;
      }
    }
    return cnt;
  }
};