/**
 * https://leetcode-cn.com/problems/sort-an-array/
 */
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
  // 快速排序
  void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int p = partition(nums, l, r);
    quickSort(nums, l, p - 1);
    quickSort(nums, p + 1, r);
  }
  int partition(vector<int>& nums, int l, int r) {
    int k = l + rand() % (r - l + 1); // 产生一个 [l,r] 间的随机数
    swap(nums[k], nums[l]); // 交换，即随机取得中轴
    int p = nums[l];
    while (l < r) {
      while (l < r && nums[r] >= p) r--;
      nums[l] = nums[r];
      while (l < r && nums[l] <= p) l++;
      nums[r] = nums[l];
    }
    nums[l] = p;
    return l;
  }
};