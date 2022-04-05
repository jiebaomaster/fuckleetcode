/**
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/solution/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-y8gh/
 * 只出现一次的元素把数组分割成两个长度为偶数的段
 * 有序数组，logn复杂度，使用二分法
 */
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (mid > 0 && nums[mid] == nums[mid - 1] && mid % 2 == 1) {
        l = mid + 1;
      } else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1] &&
                 mid % 2 == 0) {
        l = mid + 2;
      } else if (mid > 0 && nums[mid] == nums[mid - 1] && mid % 2 == 0) {
        r = mid - 2;
      } else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1] &&
                 mid % 2 == 1) {
        r = mid - 1;
      } else {
        return nums[mid];
      }
    }
    return -1;
  }
};