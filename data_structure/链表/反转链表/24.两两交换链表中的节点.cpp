/**
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * k个一组翻转的特殊情况
 */
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head) return nullptr;
    ListNode hair(0);
    hair.next = head;
    auto pre = &hair;
    auto l = head;
    auto r = head->next;
    while (r) {
      // 翻转 pre->l->r
      l->next = r->next;
      r->next = l;
      pre->next = r;

      // 移动到下一个待翻转位置
      pre = l;
      l = l->next;
      if (!l) break;
      r = l->next;
    }
    return hair.next;
  }
};

/**
 * 递归法
 */
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    auto next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
  }
};