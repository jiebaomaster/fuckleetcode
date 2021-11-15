/**
 * https://leetcode-cn.com/problems/stone-game/
 * https://labuladong.gitee.io/algo/4/30/120/
 * 
 * 原题是先手必胜的，如果石头的堆数可以是任意正整数，石头的总数也可以是任意正整数，这样就能打破先手必胜的局面了。
 * 这是一个博弈类问题。博弈问题的难点在于，两个人要轮流进行选择，而且都贼精明，如何编程表示这个过程。
 * 
 * 状态：
 *  因为每一次选择要从“子数组”的左右两端取，设计到子数组到状态可以考虑区间 DP。
 *  同时每一次选择时要区分是先手还是后手，所以这是一个三维 DP。第三维只有两种情况，可以用元祖表示。
 *  设 dp[i][j].first 为“先手”情况下，从子数组 piles[i..j] 中取石子，最多可以取到的数量
 *     dp[i][j].second 为“后手”情况下，从子数组 piles[i..j] 中取石子，最多可以取到的数量
 * 
 * 选择：
 *  每一次从子数组 piles[i..j] 中可选 piles[i] 或者 piles[j]，选择数量更大的那种
 *  即 dp[i][j].first = max(piles[i] + dp[i+1][j].second, piles[j] + dp[i][j-1].second)
 *                    = max(     选择最左边的石头堆     ,     选择最右边的石头堆      )
 *  对于先手选择 piles[i] 的情况，那么剩下的是 piles[i+1...j]，此时后手进行选择，
 *  就相当于在 piles[i+1..j] 中进行先手选择
 *  即 dp[i][j].second = dp[i+1][j].first
 */
class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

    // 只有一个可选，则先手直接选择一个，后手就没得选了
    for (int i = 0; i < n; i++) {
      dp[i][i].first = piles[i];
      dp[i][i].second = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        // 先手选子数组最左端的那个可得的数量
        int left = piles[i] + dp[i + 1][j].second;
        // 先手选子数组最右端的那个可得的数量
        int right = piles[j] + dp[i][j - 1].second;
        if (left > right) { // 先手选左端更大可得更大的值，则选左端
          dp[i][j].first = left;
          // 如果先手选择了最左边那堆，那么剩下的是 piles[i+1...j]，
          // 则当前后手进行选择，就相当于在 piles[i+1...j] 中进行先手选择
          dp[i][j].second = dp[i + 1][j].first;
        } else {
          dp[i][j].first = right;
          // 如果先手选择了最右边那堆，那么剩下的是 piles[i...j-1]，
          // 则当前后手进行选择，就相当于在 piles[i...j-1] 中进行先手选择
          dp[i][j].second = dp[i][j - 1].first;
        }
      }
    }
    // 判断先手是否能赢，即比较先手和后手可获得的数量大小
    return dp[0][n - 1].first - dp[0][n - 1].second > 0;
  }
};