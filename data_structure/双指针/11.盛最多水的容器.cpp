/**
 * https://leetcode-cn.com/problems/container-with-most-water/
 * 已知 height[left] 和 height[right] 的高度，则算出 left 和 right 之间
 * 能够盛下的水为 min(height[left], height[right]) * (right - left)
 */
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ret = -1;
    while (l < r) {
      int tmp = min(height[l], height[r]) * (r - l);
      ret = max(ret, tmp);

      /**
       * 移动较低的一边
       * 面积 = 宽 * 高，如果移动较低的那一边，那条边可能会变高，使得矩形的高度变大，
       * 进而就「有可能」使得矩形的面积变大；相反，如果移动较高的那一边，矩形的高度是
       * 无论如何都不会变大的，所以不可能使矩形的面积变得更大。
       * 这里也可以进一步移动较低的边，直到移动到出现更高的边
       */
      if (height[l] < height[r])
        l++;
      else
        r--;
    }
    return ret;
  }
};