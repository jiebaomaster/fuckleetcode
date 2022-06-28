/**
 * https://leetcode.cn/problems/max-stack/
 * 设计一个栈，支持查找/删除栈中最大元素
 * 方法一：双栈法，最大值栈
 * 时间复杂度 除了 popMax 是 O(n)，其余都是 O(1)
 */
class MaxStack {
 public:
  stack<int> nums;  // 数字栈
  stack<int> maxs;  // 最大值栈
  MaxStack() {}

  void push(int x) {
    nums.push(x);
    // 每次入栈时要同步更新最大值栈
    // 将当前入栈的最大值 压入 最大值栈
    int t = x;
    if (!maxs.empty() && maxs.top() > x) t = maxs.top();
    maxs.push(t);
  }

  int pop() {
    int t = nums.top();
    nums.pop();
    maxs.pop();
    return t;
  }

  int top() { return nums.top(); }

  int peekMax() { return maxs.top(); }

  int popMax() {
    int m = maxs.top();
    stack<int> buf;
    // 找到最大值所在位置，buf 保存最大值之上的数字
    while (!nums.empty() && m != nums.top()) {
      buf.push(pop());
    }
    pop();  // 弹出最大值
    // 最大值之上的数字 重新入栈
    while (!buf.empty()) {
      push(buf.top());
      buf.pop();
    }
    return m;
  }
};

/**
 * 方法二：双向链表 + 红黑树map
 * 双向链表用来表示栈，map中的每一个节点存储一个键值对，其中“键”表示某个在栈中出现的值，
 * “值”为一个列表，表示这个值在双向链表中出现的位置
 * 
 */
class MaxStack {
 public:
  list<int> nums;
  map<int, vector<list<int>::iterator>> npos;
  MaxStack() {}

  void push(int x) {
    nums.push_back(x);
    auto iter = --nums.end();
    npos[x].push_back(iter);
  }

  int pop() {
    auto t = nums.back();
    nums.pop_back();
    npos[t].pop_back();
    if (npos[t].empty()) {
      npos.erase(t);
    }
    return t;
  }

  int top() { return nums.back(); }

  int peekMax() { return (--npos.end())->first; }

  int popMax() {
    auto x = peekMax();
    nums.erase(npos[x].back());
    npos[x].pop_back(); // 删除最大值
    if (npos[x].empty()) {
      npos.erase(x);
    }
    return x;
  }
};