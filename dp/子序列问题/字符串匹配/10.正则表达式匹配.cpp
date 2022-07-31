/**
 * https://leetcode-cn.com/problems/regular-expression-matching/
 * https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/
 * 
 * dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
 * 1. 如果 p[j] == s[i] : dp[i][j] = dp[i-1][j-1]；
 * 2. 如果 p[j] == '.' : dp[i][j] = dp[i-1][j-1]；
 * 3. 如果 p[j] == '*'：
 *    3.1 如果 p[j-1] != s[i] : dp[i][j] = dp[i][j-2] // a* only counts as empty
 *    3.2 如果 p[j-1] == s[i] or p[j-1] == '.'：
 *        dp[i][j] = dp[i-1][j] // a* counts as multiple a
 *        or dp[i][j] = dp[i-1][j-2] // a* counts as single a
 *        or dp[i][j] = dp[i][j-2] // a* counts as empty，即前面就已经匹配了，p后面的可以不起作用
 *
 * base case:
 * 1. p为空串，s不为空串，肯定不匹配。 dp[i][0] = false
 * 2. s为空串，但p不为空串，要想匹配，只可能是右端是星号，它干掉一个字符后，
 *    把 p 变为空串。 dp[0][j] = dp[0][j - 2];
 *    如：p=a*a* 匹配 空串
 * 3. s、p都为空串，肯定匹配。dp[0][0] = true
 * 
 * 本题还可以有变形，如新的通配符 '+'，
 * '+' 相当于只能匹配一个或多个，不能匹配 0 个
 * 如果 p[j] == '*'：
 *    如果 p[j-1] == s[i] or p[j-1] == '.'：
 *        dp[i][j] = dp[i-1][j] // a* counts as multiple a
 *        or dp[i][j] = dp[i-1][j-2] // a* counts as single a
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    int ns = s.size();
    int np = p.size();
    vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));
    dp[0][0] = true;
    // s 为空串，p 不为空,
    for (int j = 1; j <= np; j++)
      if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];

    for (int i = 1; i <= ns; i++) {
      for (int j = 1; j <= np; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          if (s[i - 1] == p[j - 1 - 1] || p[j - 1 - 1] == '.')
            dp[i][j] = dp[i][j - 2]      // match 0
                       || dp[i - 1][j - 2]   // match one
                       || dp[i - 1][j];  // match n
          else
            dp[i][j] = dp[i][j - 2];  // match 0
        }
      }
    }
    return dp[ns][np];
  }
};