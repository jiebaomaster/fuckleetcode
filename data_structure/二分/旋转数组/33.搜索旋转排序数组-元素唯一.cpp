/**
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 
 * 有序的数组应想到用二分法
 * 
 * 方法一：多分类二分
 * 本题相对于普通的二分法，收缩区间的方向判断更复杂，普通二分只有两种情况，这里有6种
 * 设 nums[k] = target，m = (l+r)/2
 * 1. nums[m] > targer，当 k 和 m 在一边时，r=m-1
 *      [  k   m        ]  r=m-1
 *      [  k   m  |     ]  r=m-1
 *      [         | k m ]  r=m-1
 *      [      m  | k   ]  l=m+1
 * 2. nums[m] < targer，当 k 和 m 在一边时，l=m+1
 *      [  m   k        ]  l=m+1
 *      [  m   k  |     ]  l=m+1
 *      [         | m k ]  l=m+1
 *      [  k      | m   ]  r=m-1
 * 通过和 nums[l]、nums[r] 的比较可判断某个元素在旋转的哪一边
 */
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] > target) {
        // k 和 m 分别在旋转的两边
        if (nums[l] > target && nums[m] > nums[r])
          l = m + 1;
        else
          r = m - 1;
      } else {
        // k 和 m 分别在旋转的两边
        if (nums[m] < nums[l] && target > nums[r])
          r = m - 1;
        else
          l = m + 1;
      }
    }
    return -1;
  }
};

/**
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/shua-chuan-lc-yan-ge-ologn100yi-qi-kan-q-xifo/
 * 方法二：两次二分，先查找旋转点，再查找目标
 */
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // 1. 二分法查找旋转点的位置，旋转点将原数组分成两个有序数组
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[0] <= nums[mid])
        l = mid + 1;
      else
        r = mid;
    }

    // 2. 比较 target 和 nums[0] 的大小判断 target 在哪一段上
    if (target < nums[0]) { // 后一段 [pivot, n)
      l = l;
      r = nums.size();
    } else { // 前一段 [0, pivot)
      l = 0;
      r = r;
    }
    // 3. 在目标段中二分查找第一个大于等于 target 的数
    int rr = r;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (target > nums[mid])
        l = mid + 1;
      else
        r = mid;
    }
    // 4. 返回 target 的下标
    return (l == rr || nums[l] != target) ? -1 : l;
  }
};