/**
 * @brief 求非降序范围 [l, r) 内第一个不小于 x 的值的位置
 * 同时适用于区间为空、答案不存在、有重复元素、搜索开/闭的上/下界等情况
 * https://www.zhihu.com/question/36132386/answer/530313852
 * 
 * @return 若返回 r 则表示目标不存在
 */
int lower_bound(vector<int> &nums, int l, int r, int x) {
  while(l < r) {
    int mid = l + (r-l)/2; // 防止溢出
    if(nums[mid] < x) l = mid + 1;
    else r = mid;
  }
  return l; // 最终 l 和 r 相等，返回谁都可以
}

/**
 * 进阶，在非降序数组中用二分法查找第一个满足条件 cmp 的元素
 * 数组可看作是 [不满足, 不满足, ... 不满足, 满足, 满足, ...]
 * 
 * @return -1 表示目标不存在
 */
  int search_if(vector<int>& nums, function<bool(int)> cmp) {
    int l = 0, r = nums.size();
    while (l < r) {  // [l, r)，l==r 时退出
      int mid = l + (r - l) / 2;
      if (cmp(nums[mid])) {
        // 找第一个满足条件的元素则向左走，mid 可能就是第一个则 mid 不减 1
        r = mid;
      } else {
        // 不满足条件，右边可能存在满足条件的，往右走
        // mid 不满足条件，应该从 mid+1 开始
        // 此外当 l+1==r 时，mid=l，如果不加 1 会造成死循环
        l = mid + 1;
      }
    }
    if (l == nums.size() || !cmp(nums[l])) return -1;
    return l;
  };