/**
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
 */
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int l = 1, r = 1;
    bool inDelete = false; // 标记是否需要进行删除
    while (r < nums.size()) {
      if (inDelete) {
        if (nums[r] == nums[l - 1]) {
          r++;
        } else {
          nums[l] = nums[r];
          l++;
          r++;
          inDelete = false;
        }
      } else {
        nums[l] = nums[r];
        if (nums[r] == nums[l - 1]) inDelete = true;
        l++;
        r++;
      }
    }
    return l;
  }
};

/**
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solution/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/
 * 保留 k 位的通用解法
 * 1. 对于前 k 个数字，我们可以直接保留
 * 2. 对于后面的任意数字，能够保留的是：与当前写入的位置前面的第 k 个元素进行比较，不相同则保留
 */
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int k = 2;

    int l = 0;
    int r = 0;
    while (r < nums.size()) {
      if (l < k || nums[l - k] != nums[r]) nums[l++] = nums[r];
      r++;
    }
    return l;
  }
};