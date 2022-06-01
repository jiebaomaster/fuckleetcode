/**
 * https://leetcode.cn/problems/find-pivot-index/
 * 方法一：前缀和
 */
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    for (int i = 1; i <= n; i++) {
      if (prefix[i - 1] == prefix[n] - prefix[i]) {
        return i - 1;
      }
    }
    return -1;
  }
};

/**
 * 方法二：比较 cur 和sum 的关系
 */
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (cur * 2 == sum - nums[i]) {
        return i;
      }
      cur += nums[i];
    }
    return -1;
  }
};