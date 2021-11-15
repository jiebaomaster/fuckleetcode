/**
 * https://leetcode-cn.com/problems/super-egg-drop/
 * https://www.bilibili.com/video/BV1KE41137PK?from=search&seid=17973611971894816621
 * https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/
 * dp[i][k]表示有k个鸡蛋，从i层楼中，在最坏情况下确定恰好能摔碎楼层的最小搜索次数
 */
// 方法一：做选择时遍历求最值
class Solution {
 public:
  int superEggDrop(int K, int n) {
    // dp[i][k]表示有k个鸡蛋，从i层楼中，在最坏情况下确定恰好能摔碎楼层的最小搜索次数
    vector<vector<int>> dp(n + 1, vector<int>(K + 1));
    // 只有一个鸡蛋，只能线性搜索所有楼层
    for (int i = 1; i < n + 1; i++) dp[i][1] = i;

    for (int i = 1; i < n + 1; i++) {
      for (int k = 2; k < K + 1; k++) {
        int res = INT_MAX;
        // 从1～i层的每一层楼，扔一次鸡蛋测试，确定这次测试选择每一层对应的搜索次数，综合求得最小次数
        for (int j = 1; j <= i; j++) {
          res = min(
                    res,
                    max(
                      dp[j - 1][k - 1],  // 这次测试鸡蛋碎了，搜索楼层变低，鸡蛋个数减 1
                      dp[i - j][k]       // 这次测试鸡蛋没碎，搜索楼层变高，鸡蛋个数不变
                    ) + 1);
        }
        dp[i][k] = res;
      }
    }
    return dp[n][K];
  }
};


// 方法二： 使用二分法优化最值的寻找
class Solution {
 public:
  int superEggDrop(int K, int n) {
    // dp[i][k]表示有k个鸡蛋，从i层楼中，在最坏情况下确定恰好能摔碎楼层的最小搜索次数
    vector<vector<int>> dp(n + 1, vector<int>(K + 1));
    // 只有一个鸡蛋，只能线性搜索
    for (int i = 1; i < n + 1; i++) dp[i][1] = i;
    
    for (int i = 1; i < n + 1; i++) {
      for (int k = 2; k < K + 1; k++) {
        int lo = 1, hi = i; // 二分范围 1～i
        while (lo + 1 < hi) {
          int x = (lo + hi) / 2;
          int t1 = dp[x - 1][k - 1];  // 随x的增大，递增
          int t2 = dp[i - x][k];      // 随x的增大，递减

          // 二分法寻找 dp(k - 1, x - 1) 和 dp(k, i - x) 的交点
          if (t1 < t2) {
            lo = x;
          } else if (t1 > t2) {
            hi = x;
          } else {
            lo = hi = x;
            break;
          }
        }
        // 两个相交的函数 f1 和 f2，max{f1,f2} 的最小值必定在交点，本题是离散函数，所以在交点附近
        // 所以没必要遍历 1~i 每个楼层了，只需要比较交点附近两个点的大小
        dp[i][k] = 1 + min(max(dp[lo - 1][k - 1], dp[i - lo][k]),
                           max(dp[hi - 1][k - 1], dp[i - hi][k]));
      }
    }
    return dp[n][K];
  }
};