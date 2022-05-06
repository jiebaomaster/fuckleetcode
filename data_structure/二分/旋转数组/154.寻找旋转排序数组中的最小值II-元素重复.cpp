/**
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/gong-shui-san-xie-xiang-jie-wei-he-yuan-7xbty/
 * 
 * 类似第 153 题，只是这里元素有可能重复
 * 当旋转发生在连续重复的元素时，会破坏由 nums[0] 构成的分段性
 * 后一段存在重复元素时 nums[0] 不一定大于后一段的数了
 * 可以进行预处理，将后一段中等于 nums[0] 的数移除，重构分段性
 */
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    // 将后一段中等于 nums[0] 的数移除，重构分段性
    while (r > 0 && nums[r] == nums[0]) r--;
    r++; // 左闭右开
    int rr = r; // 记住右开的位置
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[0] <= nums[mid])
        l = mid + 1;
      else
        r = mid;
    }
    // 返回旋转点
    return l == rr ? nums[0] : nums[l];
  }
};

/**
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/
 * 方法二：右边界 nums[r] 确定的分段，特殊处理 numbers[mid] == numbers[r]
 */
class Solution {
 public:
  int minArray(vector<int>& numbers) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (numbers[mid] > numbers[r])
        l = mid + 1;
      else if (numbers[mid] < numbers[r])
        r = mid;
      else
        r--;
    }
    return numbers[r];
  }
};