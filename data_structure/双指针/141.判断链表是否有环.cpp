/**
 * https://leetcode-cn.com/problems/linked-list-cycle/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/shuang-zhi-zhen-ji-qiao#yi-kuai-man-zhi-zhen-de-chang-jian-suan-fa
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;

    ListNode *slow = head, *fast = head;
    // 快指针走到链表尾部了，说明不存在环
    while (fast != nullptr && fast->next != nullptr) {
      // 快慢指针，慢的一次走一步，快的一次走两步
      slow = slow->next;
      fast = fast->next->next;
      // 如果有环两个指针会相遇
      if (slow == fast) return true;
    }
    return false;
  }
};