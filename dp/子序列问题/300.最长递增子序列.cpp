/**
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/dong-tai-gui-hua-she-ji-zui-chang-di-zeng-zi-xu-lie
 * f(i) 为以 nums[i] 结尾的最长递增子序列的长度，则
 * f(i) = max{f(j)+1, 1} 其中 0<=j<i 且 nums[j] < nums[i]
 * 从前面已算出的最长长度的子序列中挑选出满足递增的
 */
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : 1);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

/**
 * https://leetcode.cn/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
 * 方法二：二分查找
 * 
 * 令 tails[i] 的值代表 长度为 i+1 的递增子序列 的最后一个元素的值
 * 遍历 nums，用 nums[j] 更新 递增子序列的最后一个元素
 * 若区间中存在 tails[i] > nums[j]：找到第一个满足 tails[i] > nums[j]，
 *    更新长度为 i+1 的递增子序列的末尾元素，即 tails[i]=nums[j]
 * 若区间中不存在 tails[i] > nums[j]：则 nums[j] 是更长的递增子序列的末尾元素
 */
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> tail(n, 0);
    int res = 0;
    for (int n : nums) {
      int l = 0, r = res;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (tail[mid] < n)
          l = mid + 1;
        else
          r = mid;
      }
      tail[l] = n;
      if (l == res) res++;
    }
    return res;
  }
};