/**
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/solution/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-y8gh/
 * 一个由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次
 * 只出现一次的元素把数组分割成两个长度为偶数的段
 * 可以根据下标 mid 的奇偶性和 n[mid] 与前后元素的关系确定 mid 落在前后的哪个部分
 * 
 * 下标 [0,1,...,x-2,x-1] x [x+1,x+2...]
 *     [偶,奇,偶,奇...偶,奇]x [奇,偶, 奇,偶,...]
 * 
 * 有序数组，logn复杂度，使用二分法
 */
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (mid % 2) {
        if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
          r = mid - 1;
        } else if (mid > 0 && nums[mid] == nums[mid - 1]) {
          l = mid + 1;
        } else
          return nums[mid];
      } else {
        if (mid > 0 && nums[mid] == nums[mid - 1]) {
          r = mid - 2;
        } else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
          l = mid + 2;
        } else
          return nums[mid];
      }
    }
    return -1;
  }
};