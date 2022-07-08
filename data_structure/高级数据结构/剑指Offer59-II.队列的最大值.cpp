/**
 * https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/
 * 队列是先进先出的，相当于求滑动窗口的中的最大值，可以使用单调队列
 */
class MaxQueue {
 public:
  queue<int> q;
  deque<int> maxq; // 单调递减队列

  MaxQueue() {}

  int max_value() {
    if (q.empty()) return -1;
    return maxq.front();
  }

  void push_back(int value) {
    q.push(value);
    while (!maxq.empty() && maxq.back() < value) {
      maxq.pop_back();
    }
    maxq.push_back(value);
  }

  int pop_front() {
    if (q.empty()) return -1;
    auto r = q.front();
    q.pop();
    if (r == maxq.front()) maxq.pop_front();
    return r;
  }
};
