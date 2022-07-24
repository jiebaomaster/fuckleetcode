/**
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
 * 方法一：dp
 * 类似最长公共子序列，区别在于子树组是连续的
 * 则 nums1[i] 和 nums2[j] 不想等时 dp[i][j] 必为 0
 */
class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int ret = -1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (nums1[i - 1] == nums2[j - 1]) 
          dp[i][j] = dp[i - 1][j - 1] + 1;
        ret = max(ret, dp[i][j]);
      }
    }
    return ret;
  }
};

/**
 * 方法二：滑动窗口
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/solution/zui-chang-zhong-fu-zi-shu-zu-by-leetcode-solution/
 * 
 * 我们注意到之所以两位置会比较多次，是因为重复子数组在两个数组中的位置可能不同。
 * 以 A = [3, 6, 1, 2, 4], B = [7, 1, 2, 9] 为例，它们的最长重复子数组是 [1, 2]，
 * 在 A 与 B 中的开始位置不同，
 * 如果最长重复子数组在 A 和 B 中的开始位置相同，我们就可以对这两个数组进行一次遍历，得到子数组的长度
 * 可以枚举 A 和 B 所有的对齐方式
 */
class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int i, j;
    int res = 0;
    for (int k = 0; k < n + m - 1; k++) { // 枚举 A 和 B 所有的对齐方式
      i = k < m ? 0 : k - m + 1;
      j = m - k - 1 >= 0 ? m - k - 1 : 0;

      int t = 0;
      for (; i < n && j < m; i++, j++) {
        if (nums1[i] == nums2[j]) {
          t++;
          res = max(res, t);
        } else
          t = 0;
      }
    }
    return res;
  }
};