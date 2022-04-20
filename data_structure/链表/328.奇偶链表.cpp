/**
 * https://leetcode-cn.com/problems/odd-even-linked-list/
 * 分离链表中的奇数节点和偶数节点
 */
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode odd(-1); // 奇数链表
    ListNode even(-1); // 偶数链表
    auto preOdd = &odd; // 奇数链表的尾节点
    auto preEven = &even; // 偶数链表的尾节点
    auto cur = head;
    bool isOdd = true;
    while (cur) {
      if (isOdd) {
        preOdd->next = cur;
        preOdd = cur;
      } else {
        preEven->next = cur;
        preEven = cur;
      }
      cur = cur->next;
      isOdd = !isOdd;
    }
    // 连接技术链表的尾节点和偶数链表的头节点
    preOdd->next = even.next;
    preEven->next = nullptr;
    return odd.next;
  }
};