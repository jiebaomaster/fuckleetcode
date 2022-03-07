/**
 * https://leetcode-cn.com/problems/reorder-list/
 * 首尾元素两两一组，重新排列链表
 * 1->2->3->4->5
 * 1->5->2->4->3
 * 方法一：双端队列
 * 每次弹出双端队列的首尾元素，插入尾元素到首元素之后
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == nullptr) return;
    deque<ListNode*> q;  // 双端队列
    ListNode* p = head;
    while (p) {  // 入队
      q.push_back(p);
      p = p->next;
    }
    while (1) {
      if (q.size() == 1 || q.size() == 2) {
        q.back()->next = nullptr;
        break;
      }
      // 弹出双端队列的首尾元素，插入尾元素到首元素之后
      ListNode* l = q.front();
      ListNode* r = q.back();
      r->next = l->next;
      l->next = r;
      q.pop_back();
      q.pop_front();
    }
  }
};

/**
 * 方法二：链表操作组合，找中点、反转、合并
 * 1. 快慢指针找链表中点
 * 2. 反转后半部分链表
 * 3. 合并前后两个链表
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    // 1. 快慢指针找链表中点
    // slow 指向 向上取整(n/2) 的位置，奇为中偶偏下
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // 2. 反转后半部分链表
    ListNode* pre = nullptr;
    /**
     * 当链表长度为奇数时，slow 指向中点
     *   翻转了整个下半部链表
     * 当链表长度为偶数时，slow 指向下半部链表的第一个结点
     *   cur 指向下半部链表的第二个结点，翻转链表时未翻转第一个结点，
     *   因为第一个结点实际不需要移动，所以不翻转也是正确的
     */
    ListNode* cur = slow->next;
    while (cur) {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    // 3. 合并前后链表
    slow->next = nullptr; // 前半部分的链表尾部指向 null
    ListNode* l = head; // 前
    ListNode* r = pre; // 后
    while (l && r) {
      ListNode* ln = l->next;
      ListNode* rn = r->next;
      r->next = l->next;
      l->next = r;
      l = ln;
      r = rn;
    }
  }
};