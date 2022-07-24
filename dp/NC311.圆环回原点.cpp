/**
 * https://www.nowcoder.com/practice/16409dd00ab24a408ddd0c46e49ddcf8?tpId=196&tqId=40267&ru=/exam/oj
 * 在 0~len-1 组成的圆环中，从 0 出发，走 n 步后回到 0 共有几种走法
 * 每次能顺时针或逆时针走一步
 * 
 * dp[i][j] 表示从 0 出发走 i 步到达 j 的方法数
 * 从 j-1 顺时针走一步到达 j => dp[i-1][j-1]
 * 从 j+1 逆时针走一步到达 j => dp[i-1][j+1]
 * 则 dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
 * 考虑到 j-1 和 j+1 可能会超过圆环节点的范围 0～len-1，需要取余
 * dp[i][j] = dp[i-1][(j-1+len)%len] + dp[i-1][(j+1)%len]
 */
#include <math.h>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @param len 圆环节点数
   * @param n 走的步数
   */
  int backTo0(int len, int n) {
    vector<vector<int>> dp(n+1, vector<int>(len, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < len; j++) {
        dp[i][j] = dp[i - 1][(j - 1 + len) % len] + dp[i - 1][(j + 1) % len];
        dp[i][j] %= 1000000007; // 取模防止越界
      }
    }
    return dp[n][0];
  }
};