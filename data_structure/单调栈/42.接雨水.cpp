/**
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * https://labuladong.github.io/algo/4/32/137/
 *
 * 方法一：遍历两趟
 * 方法一和方法二都是按列计算，即累加每个位置 i 处的雨水量
 * 位置 i 能达到的水柱高度和其左边的最高柱子、右边的最高柱子有关，设这两个柱子
 * 高度为 l_max 和 r_max，则位置 i 最大的水柱高度就是 min(l_max, r_max),
 * 即位置 i 处能接的雨水就是 min(l_max, r_max)-height[i]
 */
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> lMax(n);  // max{height[0...i]}
    vector<int> rMax(n);  // max{height[i...end]}
    // 1. 先将每个位置的左右最大值求出来，避免在累加时重复计算
    lMax[0] = height[0];
    for (int i = 1; i < n; i++) {
      lMax[i] = max(lMax[i - 1], height[i]);
    }
    rMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      rMax[i] = max(rMax[i + 1], height[i]);
    }
    // 2. 累加每个位置能接的雨水量
    int ret = 0;
    for (int i = 0; i < n; i++) {
      ret += min(lMax[i], rMax[i]) - height[i];
    }
    return ret;
  }
};

/**
 * 方法二：双指针写法，遍历一趟
 * 木桶原理，
 * 位置 i
 * 能达到的水柱高度和其左边的最高柱子、右边的最高柱子中更矮的那个柱子有关，
 * 对于每个位置 i 只需要知道 min{max{height[0...i]}, max{height[i...end]}}
 */
class Solution {
 public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int lMax = -1,  // max{height[0...l]}
        rMax = -1;  // max{height[r...end]}
    int ret = 0;
    while (l != r) {
      lMax = max(lMax, height[l]);
      rMax = max(rMax, height[r]);

      /**
       * 对于位置 l，已知 lMax[l]=max{height[0...l]} 和 max{height[r...end]}，
       * 尽管 rMax[l] 不等于 max{height[r...end]}，但是更矮的柱子一定是 lMax
       * 所以位置 l 处的最高水位是 lMax
       */
      if (lMax < rMax) {
        ret += lMax - height[l];
        l++;
      } else {
        ret += rMax - height[r];
        r--;
      }
    }
    return ret;
  }
};

/**
 * https://programmercarl.com/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.html#%E5%8D%95%E8%B0%83%E6%A0%88%E8%A7%A3%E6%B3%95
 *
 * 方法三：单调栈，以空间换时间
 * 按行计算，即累加每一个高度的雨水量
 * 找每个柱子左右两边第一个大于该柱子高度的柱子
 */
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int ret = 0;
    stack<int> s; // 单调栈
    s.push(0);
    for (int i = 1; i < n; i++) {
      while (!s.empty() && height[s.top()] < height[i]) {
        int lowh = height[s.top()];
        s.pop();
        if (!s.empty()) { // 栈顶的下一个元素可能不存在
          int h = min(height[i], height[s.top()]) - lowh;
          int w = i - s.top() - 1;
          ret += w * h;
        }
      }
      s.push(i);
    }
    return ret;
  }
};