/**
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 区间dp。思路参考题 516，但是本体求的是连续子串 
 * dp[i][j] 表示区间范围[i,j]（注意是左闭右闭）的子串是否是回文子串
 */
class Solution {
 public:
  string longestPalindrome(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
    pair<int, int> maxPair = {0, 0}; // 最长子串的左右边界
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < s.size(); j++) {
        if (s[i] != s[j]  // 两端不相等则s[i...j]不是回文
            || !dp[i + 1][j - 1])  // 两端相等，但内部s[i+1...j-1]不是回文，则s[i...j]不是回文
          dp[i][j] = false;
        // 在得到[i,j]区间是否是回文子串的时候，可以更新最长回文子串的左右边界
        if (dp[i][j] && (j - i) > (maxPair.second - maxPair.first)) {
          maxPair = {i, j};
        }
      }
    }

    return s.substr(maxPair.first, maxPair.second - maxPair.first + 1);
  }
};