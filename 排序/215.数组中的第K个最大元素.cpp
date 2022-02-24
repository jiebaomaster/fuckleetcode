/**
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * https://labuladong.github.io/algo/4/31/127/
 * partition 算法找位置，二分判断方向
 */
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    int l = 0, r = nums.size() - 1;
    int p;
    while (l < r) {
      p = partition(nums, l, r);
      if (p == k)
        break;
      else if (p > k) {
        r = p - 1;
      } else {
        l = p + 1;
      }
    }
    return nums[k];
  }
  // 选择第一个数作为中轴，将比中轴值小的放在左边，比中轴值大的放在右边
  // 实际选出了数组中第 k 个数，并将其放入最终位置
  int partition(vector<int>& nums, int l, int r) {
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