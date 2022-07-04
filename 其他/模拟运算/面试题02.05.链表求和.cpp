/**
 * https://leetcode.cn/problems/sum-lists-lcci/
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode hair(-1);
    auto pre = &hair;
    int c = 0;
    while (l1 || l2 || c) {
      int t = c;
      if (l1) {
        t += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        t += l2->val;
        l2 = l2->next;
      }

      auto n = new ListNode(t % 10);
      pre->next = n;
      pre = n;
      c = t / 10;
    }
    return hair.next;
  }
};