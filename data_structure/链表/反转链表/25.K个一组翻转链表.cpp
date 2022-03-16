/**
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 * 方法一：迭代法，快慢指针标注出需要翻转的范围[l,r)，翻转一次后要连接两部分链表
 */
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next) return head;
    ListNode fakeHead(0);
    fakeHead.next = head;
    auto l = head;
    auto r = head;
    auto hair = &fakeHead;  // 指向前部链表的最后一个结点
    while (r) {
      int cnt = 0;
      // 计数，右指针向前走 k 步
      while (r && cnt < k) {
        cnt++;
        r = r->next;
      }
      if (cnt < k) {  // 剩余链表结点小于 k 个，不用翻转
        hair->next = l;
        break;
      } else {  // 翻转 [l,r)
        // 前部链表的最后一个结点连接到翻转后的头节点
        hair->next = reverse(l, r);
        hair = l;  // 更新前部链表的最后一个结点
        l = r;     // 更新下一次翻转的起点
      }
    }
    return fakeHead.next;
  }
  // 翻转 [l,r)，返回翻转之后的头节点，即当前 r 的前一个
  ListNode* reverse(ListNode* l, ListNode* r) {
    ListNode* pre = nullptr;
    ListNode* cur = l;
    while (cur != r) {
      auto n = cur->next;
      cur->next = pre;
      pre = cur;
      cur = n;
    }
    return pre;
  }
};

/**
 * 方法二：递归翻转链表的头k个结点
 */
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next) return head;
    auto r = head;
    int cnt = 0;
    while (r && cnt < k) {
      cnt++;
      r = r->next;
    }
    if (cnt < k) {  // 不足 k 个的不用翻转
      return head;
    } else {
      // 翻转头 k 个结点 [head, r)
      auto n = reverse(head, r);
      // 翻转剩余链表
      // 经过翻转之后 head 指向最后一个节点，连接最后一个节点和剩余链表
      head->next = reverseKGroup(r, k);
      return n;
    }
  }
  ListNode* reverse(ListNode* l, ListNode* r) {
    ListNode* pre = nullptr;
    ListNode* cur = l;
    while (cur != r) {
      auto n = cur->next;
      cur->next = pre;
      pre = cur;
      cur = n;
    }
    return pre;
  }
};