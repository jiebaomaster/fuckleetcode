/**
 * https://leetcode-cn.com/problems/merge-sorted-array/
 * 将 n2 合并到 n1
 * 从后往前合并，可以避免错误覆盖 n1 的元素，挑选两个数组中当前元素的最大值
 */
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1;
    int p = m + n - 1;
    // 从后往前合并，可以避免错误覆盖 n1 的元素
    while (i >= 0 && j >= 0) {
      if (nums1[i] < nums2[j])
        nums1[p--] = nums2[j--];
      else
        nums1[p--] = nums1[i--];
    }
    // nums2 还有未合并的需要放入 nums1
    // nums1 还有未合并的不用额外操作，因为他本来就在 nums1 中
    while (j >= 0) { 
      nums1[p--] = nums2[j--];
    }
  }
};