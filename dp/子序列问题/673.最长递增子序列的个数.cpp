/**
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/gong-shui-san-xie-lis-de-fang-an-shu-wen-obuz/
 * 
 * 第 300 题最长递增子序列长度的进阶版，要求出最长递增子序列的个数
 * 只需要在计算以 i 结尾的最长地址子序列长度的时候额外记录个数即可
 * 最后统计总体上的 LIS 个数
 */
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> len(n);   // 以 i 结尾的最长递增子序列长度
    vector<int> size(n);  // 以 i 结尾的最长递增子序列个数
    len[0] = 1;
    size[0] = 1;
    int globalMaxLen = 1; // 整个数组的 LIS 长度
    for (int i = 1; i < n; i++) {
      int maxLen = 1; // 最长递增子序列长度
      int maxLenNum = 1; // 最长递增子序列个数
      for (int j = 0; j < i; j++) {
        // j-i 构成的递增子序列长度
        // 因为 nums[j]>=nums[i] 时 LIS 长度为 1，且只能有一个，所以curLen 应该为 -1，处理所有 nums[j] 都不小于 nums[i] 的情况
        int curLen = nums[j] < nums[i] ? len[j] + 1 : -1;
        if (curLen == maxLen) { // 和当前LIS长度一样的长度
          maxLenNum += size[j]; // 累加个数
        } else if (curLen > maxLen) { // 遇到更长的LIS
          maxLen = curLen; // 更新长度
          maxLenNum = size[j]; // 更新个数
        }
      }
      len[i] = maxLen;
      size[i] = maxLenNum;

      globalMaxLen = max(globalMaxLen, maxLen);
    }
    // 遍历数组，累加所有长度为globalMaxLen的LIS个数
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (len[i] == globalMaxLen) {
        res += size[i];
      }
    }
    return res;
  }
};