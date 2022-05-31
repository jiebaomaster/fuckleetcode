/**
 * https://leetcode.cn/problems/range-sum-query-immutable/
 * 基础前缀和
 */
class NumArray {
  vector<int> prefix;

 public:
  NumArray(vector<int>& nums) {
    prefix.resize(nums.size() + 1);
    for (int i = 1; i <= nums.size(); i++)
      prefix[i] = prefix[i - 1] + nums[i - 1];
  }

  int sumRange(int left, int right) { 
    return prefix[right + 1] - prefix[left]; 
  }
};