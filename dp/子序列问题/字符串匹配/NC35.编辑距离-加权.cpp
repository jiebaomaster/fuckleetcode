/**
 * https://www.nowcoder.com/practice/05fed41805ae4394ab6607d0d745c8e4?tpId=196&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196&difficulty=&judgeStatus=&tags=&title=&gioEnter=menu
 * 基本方法还是和第 72 题一样，但是计算过程有区别
 * 加权体现在初始化和递推过程
 */
class Solution {
 public:
  int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    // write code here
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // 注意初始化过程也要考虑加权
    for (int i = 1; i <= n; i++) dp[i][0] = i * dc;  // 编辑成空串，只能删除
    for (int j = 1; j <= m; j++) dp[0][j] = j * ic;  // 编辑空串，只能添加

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (str1[i - 1] == str2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else {
          // 不同的操作有不同的代价，选择代价最小的
          dp[i][j] = min(dp[i - 1][j - 1] + rc,
                         min(dp[i - 1][j] + dc, dp[i][j - 1] + ic));
        }
      }
    }
    return dp[n][m];
  }
};