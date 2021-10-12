/**
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * https://labuladong.github.io/algo/4/32/122/
 * 利用前缀和数组快速得到数组中某个子数组的和
 */
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    // 定义前缀和数组 sum[i] = nums[0]+...+nums[i-1]
    // 则有子数组和   sum[i...j] = sum[j+1] - sum[i]
    vector<int> sum(nums.size() + 1);

    // 前缀和 =》前缀和出现的次数
    unordered_map<int, int> prefix_times;
    prefix_times[0] = 1; // 刚开始时，前缀和为0出现了一次，匹配单元素子数组
    int res = 0;
    for (int i = 1; i < sum.size(); i++) {
      sum[i] = sum[i - 1] + nums[i - 1]; // 计算前缀和

      int target = sum[i] - k;  // 求前缀和 target 满足 sum[i] - target == k
      // target 出现的次数就是以i结尾的子数组中，满足要求的个数
      if (prefix_times.find(target) != prefix_times.end())
        res += prefix_times[target];
      prefix_times[sum[i]]++;  // 更新前缀和出现的次数
    }

    return res;
  }
};