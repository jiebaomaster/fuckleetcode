/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * 对比 88.合并两个有序数组，合并问题需要将要合并的位置考虑，
 * 合并链表中有 cur 指向 已合并链表的尾结点
 * 合并数组中有 p 指向当前将要合并数组的位置
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode head(0); // 新建一个头结点，方便操作
    ListNode* cur = &head; // 已合并链表的尾结点
    ListNode *p1 = list1, *p2 = list2;

    while (p1 && p2) {
      if (p1->val > p2->val) { // 保持 p1 指向更小的链表头
        swap(p1, p2);
      }
      // 已合并链表的尾结点 的下一个结点为 p1
      cur->next = p1;
      // 更新尾结点
      cur = cur->next;
      p1 = p1->next;
    }
    // 将剩余的加到 cur 尾部
    if (p1) cur->next = p1;
    if (p2) cur->next = p2;

    return head.next;
  }
};