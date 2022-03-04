/**
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 */
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* pre, ListNode* cur) { return pre->val > cur->val; };
    // 小顶堆
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heads(cmp);
    // 建堆，排除空指针
    for (auto h : lists) {
      if (h) heads.push(h);
    }
    ListNode fakehead(-1);
    ListNode* pre = &fakehead;
    while (!heads.empty()) {
      ListNode* cur = heads.top(); // 取堆顶，即最小元素
      heads.pop();
      pre->next = cur;
      pre = cur;
      // 如果有下一个，放入堆中
      if (cur->next) heads.push(cur->next);
    }
    return fakehead.next;
  }
};