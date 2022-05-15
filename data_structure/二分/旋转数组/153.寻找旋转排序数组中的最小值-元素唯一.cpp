/**
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-5irwp/
 * 数组的最小值即为旋转数组的旋转点
 * 二分法的本质是分段性，而不是有序性。
 * 旋转点将原数组分成两个有序数组，只要知道 mid 在前后哪一段上，就能确定边界的移动方向
 * 
 * 方法一：右边界 nums[r] 确定的分段
 * 由 nums[mid] 与 nums[r] 的大小关系可以确定 mid 在哪一段
 * nums[mid] > nums[r] 时 mid 在前一段
 * nums[mid] <= nums[r] 时 mid 在后一段
 * 需要注意的是，左边界不具有这种分段性
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

/**
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/gong-shui-san-xie-yan-ge-olognyi-qi-kan-6d969/
 * 方法二：数组首元素 num[0] 造成的分段
 * 前一段中的数必定 >= nums[0]
 * 后一段中的数必定 < nums[0]
 * 则由 nums[mid] 与 nums[0] 的大小关系可以确定 mid 在哪一段
 * 从而确定边界的移动方向，在前一段时向后移，在后一段时向前移
 */
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] >= nums[0])
        l = mid + 1;
      else
        r = mid;
    }
    // 当数组全部旋转时，mid 一直在前一段，最终 l == nums.size()
    // 实际的旋转点应该为 0
    return l == nums.size() ? nums[0] : nums[l];
  }
};