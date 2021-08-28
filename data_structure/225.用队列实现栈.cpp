class MyStack {
  queue<int> q;

 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    q.push(x);  // 直接压入队尾
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int size = q.size();
    while (--size) {  // 栈顶元素在队尾，将栈顶以下的元素全部重新入队
      int tmp = q.front();
      q.pop();
      q.push(tmp);
    }
    int top = q.front();
    q.pop();
    return top;
  }

  /** Get the top element. */
  int top() {
    int res = pop();
    q.push(res);
    return res;
  }

  /** Returns whether the stack is empty. */
  bool empty() { return q.empty(); }
};

/**
 * https://leetcode-cn.com/problems/implement-stack-using-queues/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dui-lie-shi-xian-zhan-zhan-shi-xian-dui-lie#er-yong-dui-lie-shi-xian-zhan
 *
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */