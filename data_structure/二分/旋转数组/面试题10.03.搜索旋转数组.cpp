/**
 * https://leetcode-cn.com/problems/search-rotate-array-lcci/
 * https://leetcode-cn.com/problems/search-rotate-array-lcci/solution/by-york-1d-1b18/
 *
 * 类似第 81 题，旋转多次和旋转一次的效果是一样的
 * 方法还是两次二分，先查找旋转点，再查找目标
 * 重复元素的处理可以参考第 154 题，进行预处理
 */
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    // 1. 预处理，将后一段中等于 nums[0] 的数移除，重构分段性
    while (r > 0 && nums[r] == nums[0]) r--;
    r++;
    // 2. 二分法查找旋转点的位置，旋转点将原数组分成两个有序数组
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[0] <= nums[mid])
        l = mid + 1;
      else
        r = mid;
    }
    // 3. 比较 target 和 nums[0] 的大小判断 target 在哪一段上
    if (target >= nums[0]) {
      l = 0;
      r = r;
    } else {
      l = l;
      r = nums.size();
    }
    // 4. 在目标段中二分查找第一个大于等于 target 的数
    int rr = r;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid;
    }
    return l != rr && nums[l] == target;
  }
};
