/**
 * https://leetcode-cn.com/problems/next-permutation/
 * 从数组倒着查找，找到 nums[i] 比 nums[i+1] 小的时候，就将nums[i]跟nums[i+1]到nums[nums.length - 1]当中找到一个最小的比nums[i]大的元素交换。交换后，再把nums[i+1]到nums[nums.length-1]排序，就ok了
 * 从数组倒着查找，直到 nums[i] 小于 nums[i+1]，则 [i+1...size-1] 构成降序的最大字典序
 * 问题转化为求 [i, i+1...size-1] 的下一个排列：
 * 首先从 [i+1...size-1] 中找到恰好比 nums[i] 大的数 k，
 * 与 i 交换构成 [k, i+1...i...size-1]，
 * 最后将降序序列 [i+1...i...size-1] 按生序排列即可
 * 例如：   [1,2,4,3,1] nums[i]=2
 *      => [1,3,4,2,1] nums[k]=3
 *      => [1,3,1,2,4]
 */
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    // 从数组倒着查找，直到 nums[i] 小于 nums[i+1]
    for (; i >= 0 && nums[i] >= nums[i + 1]; i--) {
    }
    if (i == -1) {  // 整个数组是从大到小的，最大字典序，整体重排
      for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
        swap(nums[i], nums[j]);
      }
      return;
    }
    // 在 [i+1...size-1] 中找到 最后一个 恰好 比 num[i] 大的
    int larger = i + 1;
    for (int j = i + 2; j < nums.size(); j++) {
      if (nums[i] < nums[j] && nums[larger] >= nums[j]) {
        larger = j;
      }
    }
    // 交换，保证 [i+1...i...size-1] 是降序的
    swap(nums[i], nums[larger]);
    // 从小到大重排 [i+1...i...size-1]
    for (int j = i + 1, k = nums.size() - 1; j < k; j++, k--)
      swap(nums[j], nums[k]);

    return;
  }
};

/**
 * 用二分查找的加快序列查找
 */
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2) return;
    int l = nums.size() - 2;
    // 1. 从数组倒着查找，直到 nums[i] 小于 nums[i+1]
    while (l >= 0 && nums[l] >= nums[l + 1]) {
      l--;
    }
    int t = l; // t 为需要交换的下标
    // [l,r] 为需要递增重排的范围
    l++;
    int r = nums.size() - 1;
    // 2. 递增排序
    while (l < r) {
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
    // 3. 在[l,r] 中找到第一个比 n[t] 大的，交换
    if (t >= 0) {  // t 合法，才需要交换，t 为 -1 时表示原始序列递增
      auto i = upper_bound(nums, t + 1, nums.size() - 1, nums[t]);
      swap(nums[t], nums[i]);
    }
  }
  // 递增序列中找第一个大于 target 的数
  int upper_bound(vector<int>& nums, int l, int r, int target) {
    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] <= target)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};