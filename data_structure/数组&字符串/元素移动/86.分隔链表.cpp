/**
 * https://leetcode-cn.com/problems/partition-list/
 * 将链表中比 x 小的元素移动到头部，保持各部分的相对顺序
 * 只需将原链表中小于x 的树拿下来单独组织到一个链表中，最后连接两个链表即可
 */
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode lesshair(-1); // 更小元素的树
    ListNode hair(-1);
    hair.next = head;
    auto insertPre = &lesshair;
    auto p = head;
    auto pre = &hair;
    while (p) {
      if (p->val < x) {
        auto next = p->next;
        // del from list
        pre->next = p->next;
        // insert to lessList
        p->next = nullptr;
        insertPre->next = p;
        insertPre = p;

        p = next;
      } else {
        pre = p;
        p = p->next;
      }
    }
    // 连接两个链表
    insertPre->next = hair.next;
    return lesshair.next;
  }
};