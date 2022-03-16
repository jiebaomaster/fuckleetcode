class MyQueue {
  stack<int> s1;  // 入队栈
  stack<int> s2;  // 出队栈
 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { s1.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int res = peek();
    s2.pop();
    return res;
  }

  /** Get the front element. */
  int peek() {
    if (s2.empty()) {  // 只有出队栈空的时候，才将入队栈的元素移动到出队栈
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dui-lie-shi-xian-zhan-zhan-shi-xian-dui-lie#yi-yong-zhan-shi-xian-dui-lie
 *
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */