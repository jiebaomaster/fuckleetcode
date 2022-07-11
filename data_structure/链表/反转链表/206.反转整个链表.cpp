/**
 * https://leetcode-cn.com/problems/reverse-linked-list/
 * 如果链表中有环，递归的写法会死循环，迭代写法会不死循环，而是使得
 * 环内的链表反转，环外的未反转
 * 
 * 方法一：迭代写法
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    auto* cur = head;
    while (cur) {
      auto* next = cur->next;  // 临时节点，暂存当前节点的下一节点，用于后移
      cur->next = prev;  // 将当前节点指向它前面的节点
      prev = cur;        // 前指针后移
      cur = next;        // 当前指针后移
    }
    return prev;
  }
};

/**
 * 方法二：递归写法
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    // 递归反转下一结点
    auto ret = reverseList(head->next);
    // 处理下一结点的next指向
    head->next->next = head;
    head->next = nullptr;
    return ret;  // 返回头结点
  }
};