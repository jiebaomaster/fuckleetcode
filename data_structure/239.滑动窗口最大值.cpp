/**
 * https://leetcode-cn.com/problems/sliding-window-maximum/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dan-tiao-dui-lie
 */

class Monoqueue {
  deque<int> q;  // 单调递减队列
 public:
  // 队尾入队
  void push(int x) {
    // 入队前先弹出队尾所有较小的元素，维护队列递减
    // 因为求的是滑动窗口内的最大值，所以我们只需要在队列中保存有可能是最大值的元素
    // 两个较大值之间的较小值不可能是滑动窗口的最大值
    while (!q.empty() && x > q.back()) q.pop_back();
    q.push_back(x);
  }

  // 队首出队
  void pop(int x) {
    // 滑动窗口中较小值已经在push时出队了，只需要处理较大值的出队
    if (x == q.front()) q.pop_front();
  }

  // 由于队列元素单调递减，队首元素就是滑动窗口的最大值
  int max() { return q.empty() ? -100000 : q.front(); }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 滑动窗口中的元素是FIFO的，故想到用队列
    Monoqueue monoqueue;  // 单调递减队列
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      monoqueue.push(nums[i]);
      // 刚开始 k-1 个元素之间入队
      if (i == k - 1) { // 第 k 个元素开始产生最大值
        res.push_back(monoqueue.max());
      } else if (i >= k) { // 之后的元素入队需要移动窗口
        // 滑动窗口向前移动
        monoqueue.pop(nums[i - k]);
        res.push_back(monoqueue.max());
      }
    }
    return res;
  }
};