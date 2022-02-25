/**
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 *
 * 遍历所有柱子，以每根柱子的高度作为高的矩形面积，最终比较出最大的矩形面积。
 * 以当前柱子 i 的高度作为矩形的高，那么矩形的宽度边界即为向左找到第一个高度小于
 * 当前柱子 i 的柱子 l，向右找到第一个高度小于当前柱子 i 的柱子 r。
 * 即要找到左右两边第一个高度小于当前柱子的柱子 l 和 r，则 area = h[i] * (r-l-1)
 *
 * 方法一，暴力写法
 */
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ret = 0;
    for (int i = 0; i < heights.size(); i++) {
      int left = i - 1;
      int right = i + 1;
      while (left >= 0 && heights[left] >= heights[i]) left--;
      while (right < heights.size() && heights[right] >= heights[i]) right++;

      int w = right - left - 1;

      ret = max(ret, heights[i] * w);
    }
    return ret;
  }
};

/**
 * 方法二，单调栈
 * 暴力写法中，需要再嵌套一层 while 循环来向左找到第一个比柱体 i 高度小的柱体，这个过程是 O(N) 的；
 * 使用单调增栈可以 O(1) 的获取柱体 i 左边第一个比它小的柱体。因为一个栈顶到栈底元素从大到小的单调栈，
 * 对于栈顶的柱体来说，栈顶的下一个柱体就是左边第一个高度小于自身的柱体。
 */
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ret = 0;
    stack<int> s; // 栈顶到栈底元素从大到小
    heights.push_back(0); // 最后用一个0使得栈中的元素全部出栈，即计算所有高度
    s.push(0);
    for (int i = 1; i < heights.size(); i++) {
      while (!s.empty() && heights[i] < heights[s.top()]) {
        int mid = s.top();
        s.pop();
        int l = s.empty() ? -1 : s.top(); // 栈顶的下一个元素可能不存在
        int w = i - l - 1;
        int area = heights[mid] * w;
        ret = max(area, ret);
      }
      s.push(i);
    }
    return ret;
  }
};