/**
 * https://leetcode-cn.com/problems/add-two-numbers-ii/
 * 链表是正序的，为了相加方便先翻转两个链表，再进行链表相加
 * 为了相加结果是正序的，生成新链表时使用头插法
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 1. 先翻转两个链表
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    // 2. 链表相加
    auto p = l1;
    auto q = l2;
    ListNode hair(-1);
    int carry = 0;
    while (p || q || carry) {
      int t = carry;
      if (p) {
        t += p->val;
        p = p->next;
      }
      if (q) {
        t += q->val;
        q = q->next;
      }
      carry = t / 10;
      t %= 10;
      auto node = new ListNode(t);
      // 为了相加结果是正序的，这里使用头插法
      node->next = hair.next;
      hair.next = node;
    }
    return hair.next;
  }
  // 翻转链表
  ListNode* reverseList(ListNode* node) {
    ListNode* pre = nullptr;
    ListNode* cur = node;
    while (cur) {
      auto next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};