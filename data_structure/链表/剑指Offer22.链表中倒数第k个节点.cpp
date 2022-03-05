/**
 * https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 * 
 */
class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (k--) { // 快指针先走k步
      fast = fast->next;
    }
    // 一起走，则快指针到最后的时候，慢指针指向倒数第k个
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};