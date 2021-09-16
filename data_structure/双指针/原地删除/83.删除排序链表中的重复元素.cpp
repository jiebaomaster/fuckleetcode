/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    slow->next = nullptr; // 最后一个节点的后续节点为 null

    return head;
  }
};