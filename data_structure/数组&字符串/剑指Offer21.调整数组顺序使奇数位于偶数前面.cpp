/**
 * https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 * 前后指针
 */
class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {

    int l = 0, r = nums.size() - 1;
    while (l < r) {
      // 从前往后找一个偶数
      while (l < r && nums[l] % 2) l++;
      // 从后往前找一个奇数
      while (l < r && nums[r] % 2 == 0) r--;
      swap(nums[l], nums[r]);
    }
    return nums;
  }
};