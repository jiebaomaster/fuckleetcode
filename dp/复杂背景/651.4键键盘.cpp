/**
 * https://leetcode-cn.com/problems/4-keys-keyboard/
 * https://labuladong.gitee.io/algo/3/26/91/
 * 定义：dp[i] 表示 i 次操作后最多能显示多少个 A
 * 选择：最后一个按键只有两种情况：A 或者 Ctrl-V，Ctrl-V 前必须要有（Ctrl-A+Ctrl-C），
 *      且最后可能是连续的 Ctrl-V，那么需要选择（Ctrl-A+Ctrl-C）发生的位置，假设第一个
 *      Ctrl-V 的位置为 j（3<=j<=n），则 Ctrl-A 发生时屏幕上有 dp[j-3] 个 A，
 *      共进行了 n-j+1 次 Ctrl-V，总共 dp[j-3] + dp[j-3] + (n-j+1) = dp[j-3] * (n-j+2) 个 A
 * 
 *      ...A  Ctrl-A  Ctrl-C  Ctrl-V ... Ctrl-V
 *        j-3  j-2     j-1      j           n
 * 
 */
class Solution {
 public:
  int maxA(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1] + 1; // 最后按键为 A
      for (int j = i; j >= 3; j--) { // 最后按键为 Ctrl-V
        dp[i] = max(dp[i], dp[j - 3] * (i - j + 2));
      }
    }
    return dp[n];
  }
};