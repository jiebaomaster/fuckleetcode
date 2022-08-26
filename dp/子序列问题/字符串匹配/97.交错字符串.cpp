/**
 * https://leetcode-cn.com/problems/interleaving-string/
 * https://leetcode-cn.com/problems/interleaving-string/solution/lei-si-lu-jing-wen-ti-zhao-zhun-zhuang-tai-fang-ch/
 * 能否用 s1 和 s2 拼接成 s3，s1和s2可构成一个矩阵，每次选择一个字符相当于从左上角走到右下角，
 * 每个字符都是从 s1（向下）或者 s2（向右）拿到的，所以只要判断是否存在一条 s3 的路径即可；
 * 类似第 62 题，求矩阵中是否存在一条路径
 * 字符串匹配问题应第一时间想到 DP
 * 
 * dp[i][j] 表示 s1 前 i 个字符与 s2 前 j 个字符能否拼接成 s3 的 i+j 字符
 */
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    if (n + m != s3.size()) return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) { // 只用 s1
      if (s1[i - 1] == s3[i - 1]) {
        dp[i][0] = dp[i - 1][0];
      } else
        break;
    }
    for (int j = 1; j <= m; j++) { // 只用 s2
      if (s2[j - 1] == s3[j - 1]) {
        dp[0][j] = dp[0][j - 1];
      } else
        break;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        // 两边都可以走
        if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else if (s1[i - 1] == s3[i + j - 1]) { // 走 s1
          dp[i][j] = dp[i - 1][j];
        } else if (s2[j - 1] == s3[i + j - 1]) { // 走 s2
          dp[i][j] = dp[i][j - 1];
        } else {
          dp[i][j] = false;
        }
      }
    }
    return dp[n][m];
  }
};

/**
 * 三维dp，直接模拟
 */
class Solution {
public:
 bool isInterleave(string s1, string s2, string s3) {
   int n = s1.size();
   int m = s2.size();
   if (n + m != s3.size()) return false;
   
   vector<vector<vector<bool>>> dp(
       n + 1, vector<vector<bool>>(m + 1, vector<bool>(s3.size() + 1)));
   dp[0][0][0] = true;
   for (int i = 1; i <= n; i++)
     if (s1[i - 1] == s3[i - 1]) dp[i][0][i] = dp[i - 1][0][i - 1];
   for (int j = 1; j <= m; j++)
     if (s2[j - 1] == s3[j - 1]) dp[0][j][j] = dp[0][j - 1][j - 1];
   for (int i = 1; i <= n; i++) {
     for (int j = 1; j <= m; j++) {
       for (int k = 1; k <= s3.size(); k++) {
         if (s1[i - 1] == s3[k - 1]) dp[i][j][k] = dp[i - 1][j][k - 1];
         if (s2[j - 1] == s3[k - 1])
           dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][k - 1];
       }
     }
   }
   return dp[n][m][s3.size()];
 }
};