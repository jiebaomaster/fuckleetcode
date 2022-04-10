/**
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * https://labuladong.github.io/algo/4/32/122/
 * 这里不能用滑动窗口的原因是存在负数，不能确定窗口移动方向
 *
 * 利用前缀和数组快速得到数组中某个子数组的和
 * 
 * 类似第 1 题求 n[i] + n[j] = k 的方案数，当 i 固定时，k-n[i] 出现的次数
 * 本题求 prefix[i] - prefix[j] = k 的方案数，
 * 即当 i 固定时，在 0～i 的累加和中 prefix[i]-k 出现的次数
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

/**
 * O(n^2) 遍历每个窗口，由前缀和求得窗口和，会超时
 */
class Solution1 {
public:
 int subarraySum(vector<int>& nums, int k) {
   vector<int> prefix(nums.size() + 1);  // 0~i-1
   prefix[0] = 0;
   for (int i = 1; i <= nums.size(); i++)
     prefix[i] = prefix[i - 1] + nums[i - 1];

   int res = 0;
   for (int i = 0; i < nums.size(); i++) {
     for (int j = i + 1; j <= nums.size(); j++) {
       if (prefix[j] - prefix[i] == k) res++;
     }
   }
   return res;
 }
};