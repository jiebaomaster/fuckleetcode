/**
 * https://leetcode.cn/problems/squares-of-a-sorted-array/
 * 先找到最小的，再从该点出发往两边走，合并升序链表
 */
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int i = 0;
    while (i < nums.size() && nums[i] < 0) i++;
    vector<int> res;
    int l = i - 1, r = i;
    while (l >= 0 && r < nums.size()) {
      if (abs(nums[l]) > abs(nums[r])) {
        res.push_back(nums[r] * nums[r]);
        r++;
      } else {
        res.push_back(nums[l] * nums[l]);
        l--;
      }
    }
    while (l >= 0) {
      res.push_back(nums[l] * nums[l]);
      l--;
    }
    while (r < nums.size()) {
      res.push_back(nums[r] * nums[r]);
      r++;
    }
    return res;
  }
};