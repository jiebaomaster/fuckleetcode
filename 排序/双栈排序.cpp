/**
 * https://mp.weixin.qq.com/s/g_AqwsSEUwlRSevnStPkEA
 * 利用一个辅助栈将栈排序，类似于 面试题03.05
 * 将辅助栈看作一个满足排序性的目标栈，将待排序栈的所有元素压入辅助栈，并保持辅助栈的排序性
 * 增量思想，每次操作待排序栈中的一个元素，
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> stackSort(stack<int> &st) {
  stack<int> buf;  // 辅助栈

  // 排序每一个元素
  while (!st.empty()) {
    int cur = st.top(); // 当前需要压入辅助栈的元素
    st.pop();
    
    /* 将一个元素压入满足排序性的辅助栈 */
    int cnt = 0;
    // 在辅助栈中找到第一个比 cur 小的
    while (!buf.empty() && buf.top() > cur) {
      st.push(buf.top()); // 借助待排序栈保存从辅助栈中弹出的元素
      buf.pop();
      cnt++;
    }
    // 压入元素
    buf.push(cur);
    // 曾经弹出的元素压回辅助栈
    while (cnt--) {
      buf.push(st.top());
      st.pop();
    }
  }
  // 辅助栈满足排序性
  return buf;
}

int main() {
  vector<int> v{2, 1, 4, 5, 0, 7};
  stack<int> s;
  for (auto n : v) {
    s.push(n);
  }
  auto res = stackSort(s);
  while (!res.empty()) {
    cout << res.top() << " ";
    res.pop();
  }
}