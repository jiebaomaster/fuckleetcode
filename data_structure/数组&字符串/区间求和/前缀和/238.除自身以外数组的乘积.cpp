/**
 * https://leetcode.cn/problems/product-of-array-except-self/
 * 一个整数数组 nums，返回数组 answer，其中 answer[i] 等于 nums 中除 nums[i]
 * 之外其余各元素的乘积 answer[i] = 左半边乘积 * 右半边乘积
 * 方法一：直接求出前缀乘积
 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n + 1);
    left[0] = 1;
    for (int i = 1; i <= n; i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }
    vector<int> right(n + 1);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      right[i] = right[i + 1] * nums[i + 1];
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = left[i] * right[i];
    }
    return res;
  }
};

/**
 * 方法二：思路相同，用一个变量保存前缀乘积
 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int left = 1;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = left;
      left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
      res[i] *= right;
      right *= nums[i];
    }
    return res;
  }
};