/**
 * https://leetcode-cn.com/problems/palindrome-linked-list/
 * 
 */
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    auto slow = head;
    auto fast = head;
    // 快慢指针找链表中点
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // slow 指向后半个链表的头节点
    // 翻转后半个链表
    ListNode* prev = nullptr;
    while (slow) {
      auto n = slow->next;
      slow->next = prev;
      prev = slow;
      slow = n;
    }
    // 比较前半个链表和翻转后的后半个链表
    auto p = head;
    while (p && prev) {
      if (p->val != prev->val) return false;
      p = p->next;
      prev = prev->next;
    }
    return true;
  }
};