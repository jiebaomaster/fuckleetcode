/**
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
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
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) return nullptr;
    // 判断是否有环
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {  // 有环
        // 计算环的大小，slow走环一圈，双指针再次相遇代表走完一圈
        int count = 0;
        do {
          slow = slow->next;
          count++;
        } while (slow != fast);
        // 从头开始，fast先走count步，则双指针会相遇在环的入口节点处
        slow = fast = head;
        while (count--) {
          fast = fast->next;
        }
        while (slow != fast) {
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      };
    }
    return nullptr;
  }
};