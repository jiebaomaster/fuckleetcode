/**
 * https://leetcode-cn.com/problems/edit-distance/
 * https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/
 * dp[i][j] 代表 word1[0...i] 转换成 word2[0...j] 需要的最少步数
 * 1. 当 word1[i] == word2[j] 时，这一步不需要改变，则 dp[i][j] = dp[i-1][j-1]
 * 2. 当 word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
 *      dp[i-1][j-1]，先将 word1 的前 i-1 个字符转换为 word2 的前 j-1 个字符，然后将 word1[i] 改为 word2[j]
 *      dp[i][j-1]，先将 word1 的前 i 个字符转换为 word2 的前 j-1 个字符，然后在 word1 末尾插入 word2[j]
 *      dp[i-1][j]，先将 word1 的前 i-1 个字符转换为 word2 的前 j 个字符，然后删除 word1 末尾字符 word1[j]
 */
class Solution {
 public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

    // 转化空串所需步骤为非空串的长度，一直插入即可
    for (int i = 1; i <= word1.size(); i++) dp[i][0] = i;
    for (int j = 1; j <= word2.size(); j++) dp[0][j] = j;

    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      }
    }
    return dp[word1.size()][word2.size()];
  }
};