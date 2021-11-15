/**
 * https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/
 * https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/solution/ k-zhan-zhong-zhuan-nei-zui-bian-yi-de-ha-abzi/
 * https://labuladong.gitee.io/algo/3/24/82/
 * 
 * dp[i][j] 表示从 src 出发恰好经过 i 步到达 j 地的最小花费
 * 则 dp[i][j]= min{dp[i-1][from] + price_from_j}，需要遍历所有的节点j的入度
 * 
 * 一般情况下应该先遍历 i 和 j，再遍历 flights 寻找所有的 [from,j] 求出最小值 dp[i][j]；本题中我们
 * 可以直接遍历 flights，最小值和求值的顺序没有关系，且遍历 j 和遍历 flights 实际都是为了找 [from,j]
 */
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    const int INF = 0x3f3f3f3f; // 表示不可达性
    // dp[i][j] 表示从 src 出发恰好经过 i 步到达 j 地的最小花费
    // 要求不超过 k 次转机，则等价于不超过 k+1 条边
    vector<vector<int>> dp(k + 2, vector<int>(n, INF));
    dp[0][src] = 0;
    for (int i = 1; i < k + 2; i++) {
      for (auto f : flights) {
        int from = f[0], to = f[1], price = f[2];
        dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
      }
    }

    int res = INF;
    // 题目要求不超过k+1步，dp求得的是恰好i步，需要遍历1～k+1步求得最小值
    for (int i = 1; i < k + 2; i++) res = min(res, dp[i][dst]);

    return res >= INF ? -1 : res;
  }
};