/**
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 方法一：最小堆
 * k 个列表，每个链表长度为 n，时间 O(nk * logk)
 */
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* lhs, ListNode* rhs) { return lhs->val > cur->rhs; };
    // 小顶堆
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heads(cmp);
    // 建堆，排除空指针
    for (auto h : lists) {
      if (h) heads.push(h);
    }
    ListNode fakehead(-1);
    auto* pre = &fakehead;
    while (!heads.empty()) {
      auto* cur = heads.top(); // 取堆顶，即最小元素
      heads.pop();
      pre->next = cur;
      pre = cur;
      // 如果有下一个，放入堆中
      if (cur->next) heads.push(cur->next);
    }
    return fakehead.next;
  }
};

/**
 * 方法二：连续合并2个链表
 * k 个列表，每个链表长度为 n，时间 O(nk^2)
 */
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    while (1) {
      if (lists.size() == 1) return lists.back();
      // 合并末尾两个
      auto l1 = lists.back();
      lists.pop_back();
      auto l2 = lists.back();
      lists.pop_back();
      // 合并完成的重新入栈
      lists.push_back(mergeTwoList(l1, l2));
    }
  }
  // 合并两个链表
  ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
      l1->next = mergeTwoList(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoList(l1, l2->next);
      return l2;
    }
  }
};
