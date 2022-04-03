/**
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-5irwp/
 * 类似于 33 题，与边界进行比较判断收缩区间的方向
 */
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[r])
        l = mid + 1;
      else
        r = mid;
    }
    return nums[l];
  }
};