/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 * 大数加法，链表结构
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode fakeHead(0);
    ListNode* pre = &fakeHead;
    int carry = 0;  // 进位
    while (l1 || l2 || carry) {
      int tmp = carry;
      if (l1) {  // 如果链表还没走完，加上链表结点的值
        tmp += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        tmp += l2->val;
        l2 = l2->next;
      }
      carry = tmp / 10;  // 计算进位
      // 尾插法
      pre->next = new ListNode(tmp % 10);
      pre = pre->next;
    }
    return fakeHead.next;
  }
};