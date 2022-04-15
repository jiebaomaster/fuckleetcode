/**
 * https://leetcode-cn.com/problems/rotate-list/
 * 说是旋转链表，其实只需要找到断开的地方，重新按要求连接
 * 需要注意移动点会超过链表长度，需要取余
 */
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head;
    ListNode hair(-1);
    hair.next = head;
    // 计算链表长度
    int len = 1;
    while (head->next) {
      len++;
      head = head->next;
    }
    // 更新循环点
    k %= len;
    if (k == 0) return hair.next;

    // 找到断开点
    auto r = hair.next;
    auto l = &hair;
    while (k--) {
      r = r->next;
    }
    while (r) {
      r = r->next;
      l = l->next;
    }
    // 此时 l 和 l.next 处断开
    auto pre = l;
    l = l->next;
    pre->next = nullptr;
    // 此时 head 指向最后一个节点
    // l 指向断开后的第一个节点
    head->next = hair.next;
    hair.next = l;

    return hair.next;
  }
};