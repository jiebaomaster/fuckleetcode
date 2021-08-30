/**
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/er-fen-cha-zhao-xiang-jie
 */
class Solution {
 public:
  // 在有序数组中用二分法查找第一个满足条件 cmp 的元素
  int search_if(vector<int>& nums, function<bool(int)> cmp) {
    int l = 0, r = nums.size();
    while (l < r) {  // [l, r)，l==r 时退出
      int mid = l + (r - l) / 2;
      if (cmp(nums[mid])) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (l == nums.size() || !cmp(nums[l])) return -1;
    return l;
  };
  vector<int> searchRange(vector<int>& nums, int target) {
    // 查找左端，即第一个大于等于的数，注意不能直接查等于
    auto cmpleft = [target](int mid) { return mid >= target; };
    int left = search_if(nums, cmpleft);

    // 序列中有可能没有等于的数，但有大于的数，也算查找失败
    if (left == -1 || nums[left] != target) return {-1, -1};

    // 查找右端，即第一个大于的数下标减一
    auto cmpright = [target](int mid) { return mid > target; };
    int right = search_if(nums, cmpright);

    if (right ==
        -1)  // 不存在大于的数，当前面已有等于的数，说明一直到末尾都是等于的数
      return {left, static_cast<int>(nums.size()) - 1};
    else
      return {left, right - 1};
  }
};