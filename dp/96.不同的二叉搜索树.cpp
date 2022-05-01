/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees/
 * https://programmercarl.com/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html#%E6%80%9D%E8%B7%AF
 * 
 * dp[i] 表示 i 个不同元素节点组成的二叉搜索树的个数
 * 可将 1～i 元素分别作为根节点，求二叉树的个数
 * 若以 j(1<=j<=i) 为根节点，根据二叉搜索树的性质:
 *    j 左边有 1~j-1 共 j-1 个元素，
 *    j 右边有 j+1~i 共 i-j 个元素
 * 则以 j 作为根节点构成的二叉搜索树有 dp[j-1]*dp[i-j] 个
 * 
 */
class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};