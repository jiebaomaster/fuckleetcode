/**
 * https://leetcode-cn.com/problems/find-peak-element/
 * O(logN)一般考虑二分搜索。有如下规律：
 * 函数极值与单调性的关系
 * 规律一：如果nums[i] > nums[i+1]，递减函数，则在i之前一定存在峰值元素
 * 规律二：如果nums[i] < nums[i+1]，递增函数，则在i+1之后一定存在峰值元素
 */
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[mid + 1]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};