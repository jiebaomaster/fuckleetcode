/**
 * https://www.lintcode.com/problem/42/description
 * 53 题的升级版，因为两个子数组不重叠，所以必定存在一条分割线分开这两个子数组，
 * 只需要遍历这条分界线的位置 i，在 [0,i] 和 [i+1, n-1] 中分别找最大连续子数组和
 */
class Solution {
 public:
  /**
   * @param nums: A list of integers
   * @return: An integer denotes the sum of max two non-overlapping subarrays
   */
  int maxTwoSubArrays(vector<int> &nums) {
    vector<int> left = nums;
    vector<int> right = nums;

    // 1. 求以 nums[i] 结尾的最大连续子数组和
    // 计算 0->i 中以 nums[i] 结尾的最大连续子数组和
    for (int i = 1; i < nums.size(); i++) {
      left[i] = max(left[i - 1] + nums[i], nums[i]);
    }
    // 计算 n-1->i 中以 nums[i] 结尾的反向最大连续子数组和
    for (int i = nums.size() - 2; i >= 0; i--) {
      right[i] = max(right[i + 1] + nums[i], nums[i]);
    }
    
    // 2. 求前缀最大值
    // 计算 0->i 中到 nums[i] 为止的最大连续子数组和
    for (int i = 1; i < nums.size(); i++) {
      left[i] = max(left[i - 1], left[i]);
    }
    // 计算 n-1->i 中到 nums[i] 为止的反向最大连续子数组和
    for (int i = nums.size() - 2; i >= 0; i--) {
      right[i] = max(right[i + 1], right[i]);
    }

    // 3. 遍历分界线的位置
    int res = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++) {
      res = max(res, left[i] + right[i + 1]);
    }
    return res;
  }
};