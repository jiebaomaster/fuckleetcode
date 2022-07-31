/**
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-3/mu-lu-ye-2/yuan-di-xiu-gai-shu-zu#you-xu-shu-zu-lian-biao-qu-zhong
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;

    // 快慢指针
    // 因为链表有序，所以慢指针保存的是最大的不重复数字的位置
    ListNode *slow = head, *fast = head->next;
    while (fast != nullptr) {  // 遍历整个链表
      if (slow->val !=
          fast->val) {  // 每次遇到不相同的，储存到慢指针的下一个位置
        slow = slow->next;
        slow->val = fast->val;
      }
      fast = fast->next;
    }
    slow->next = nullptr;  // 最后一个节点的后续节点为 null

    return head;
  }
};

class Solution1 {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto l = head; // l 指向重复部分的第一个节点
    auto r = head;
    while (r) {
      // 跳过所有重复的
      while (r && l->val == r->val) {
        r = r->next;
      }
      // 此时 r 指向下一个不重复的
      l->next = r;
      l = r;
    }

    return head;
  }
};

/**
 * 递归
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;
    while (head->next && head->val == head->next->val) {
      head = head->next;
    }
    head->next = deleteDuplicates(head->next);
    return head;
  }
};