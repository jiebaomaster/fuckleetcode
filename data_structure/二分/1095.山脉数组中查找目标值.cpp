/**
 * https://leetcode.cn/problems/find-in-mountain-array/
 * 参考第 154 题，先寻找峰值，再在峰值的左右两边查找 target
 * 寻找峰值的方法可以参考第 162 题
 */
class Solution {
 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (mid + 1 < n && mountainArr.get(mid) < mountainArr.get(mid + 1))
        l = mid + 1;
      else
        r = mid;
    }

    int left = findInLeft(target, 0, l, mountainArr);
    if (left != -1) // 左边找到的话可以直接返回
      return left;
    else // 否则去右边找
      return findInRight(target, l, n, mountainArr);
  }
  int findInLeft(int target, int l, int r, MountainArray &mountainArr) {
    int rr = r;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (target > mountainArr.get(mid))
        l = mid + 1;
      else
        r = mid;
    }
    return l == rr || target != mountainArr.get(l) ? -1 : l;
  }
  int findInRight(int target, int l, int r, MountainArray &mountainArr) {
    int rr = r;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (target < mountainArr.get(mid))
        l = mid + 1;
      else
        r = mid;
    }
    return l == rr || target != mountainArr.get(l) ? -1 : l;
  }
};