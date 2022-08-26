/**
 * https://leetcode-cn.com/problems/sort-list/
 * 方法一：归并排序，递归（自顶向下）
 */
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* preSlow = nullptr;  // slow 的前一个结点
    while (fast && fast->next) {
      preSlow = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    /**
     * 此时 slow 指向前半个链表的最后一个结点
     * 链表的归并排序要求所排序的部分链表最后一个结点的 next 指向 null，
     * 否则 merge 时无法判断什么时候合并结束
     */
    preSlow->next = nullptr;
    // [s...preSlow, null] 前半部分
    ListNode* p1 = sortList(head);
    // [slow...end, null] 后半部分
    ListNode* p2 = sortList(slow);

    // merge
    ListNode fakeHead(0);
    ListNode* pre = &fakeHead;
    while (p1 && p2) {
      if (p1->val < p2->val) {
        pre->next = p1;
        pre = p1;
        p1 = p1->next;
      } else {
        pre->next = p2;
        pre = p2;
        p2 = p2->next;
      }
    }
    if (p1) pre->next = p1;
    if (p2) pre->next = p2;

    return fakeHead.next;
  }
};

/**
 * 方法二：归并排序，迭代（自底向上）
 * 先 2 个 2 个的 merge，完成一趟后，再 4 个 4 个的 merge，直到结束。例如：
 * step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
 * step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
 * step=4: (1->2->3->4->7->8->9->11)->(5->6)
 * step=8: (1->2->3->4->5->6->7->8->9->11)
 */
class Solution1 {
 public:
  ListNode* sortList(ListNode* head) {
    ListNode fakeHead(-1); // 处理链表的第一个结点在变化的情况
    fakeHead.next = head;
    auto p = head;
    int cnt = 0;
    while (p) { // 计算链表长度
      cnt++;
      p = p->next;
    }
    for (int step = 1; step < cnt; step *= 2) {
      auto cur = fakeHead.next; // 从链表的第一个结点开始
      auto pre = &fakeHead; // 本趟已处理的最后一个结点，用于合并完成之后的连接
      while (cur) { // step step 归并
        // 初始链表 pre->cur->...->null
        // 1. 切第一个链表 
        // pre->cur->...->null   nextList->...->null
        auto nextList = cut(cur, step);
        // 2. 切第二个链表
        // pre->cur->...->null   nextList->...->null   other->...->null
        auto other = cut(nextList, step);
        // 3. 合并第一个和第二个 
        // pre->(cur~nextList)->null other->...->null
        pre->next = merge(cur, nextList);
        // 4. 更新下一次合并的开始结点，更新已处理合并的最后一个结点
        // fakeHead->(cur~nextList)->pre->null cur->...->null
        cur = other; // 更新下一次合并的开始结点
        while (pre->next) pre = pre->next;
      }
    }
    return fakeHead.next;
  }
  /**
   * 将链表 head 切掉前 n 个节点，并返回后半部分的链表头
   * head->...->last->next->...->null
   * =>  head->...->last->null  next->...->null
   * 返回 next
   */
  ListNode* cut(ListNode* head, int n) {
    auto last = head;
    while (--n && last) {
      last = last->next;
    }
    if (!last) return nullptr;

    auto next = last->next;
    last->next = nullptr;
    return next;
  }

  // 合并两个链表
  ListNode* merge(ListNode* l, ListNode* r) {
    ListNode fakeHead(-1);
    ListNode* pre = &fakeHead;
    while (l && r) {
      if (l->val < r->val) {
        pre->next = l;
        pre = l;
        l = l->next;
      } else {
        pre->next = r;
        pre = r;
        r = r->next;
      }
    }
    if (l) pre->next = l;
    if (r) pre->next = r;
    return fakeHead.next;
  }
};

/**
 * 方法三：快速排序
 */
class Solution2 {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    return quickSort(head, nullptr);
  }
  ListNode* quickSort(ListNode* head, ListNode* end) {
    if (!head || head->next == nullptr) return head;

    auto poivt = head; // 以第一个节点为中轴
    ListNode smaller(-1); // 比中轴小的
    ListNode bigger(-1);  // 比中轴大的
    auto preS = &smaller;
    auto preB = &bigger;
    auto p = poivt->next; // 从中轴的下一个开始
    while (p != end) { // 将链表分为两份
      if (p->val < poivt->val) {
        preS->next = p;
        preS = p;
        p = p->next;
      } else {
        preB->next = p;
        preB = p;
        p = p->next;
      }
    }
    // smaller -> poivt -> bigger -> end
    // 排序前半段 [smaller, poivt)
    preS->next = poivt;
    smaller.next = doQuickSort(smaller.next, poivt);
    // 排序后半段 [bigger, end)
    preB->next = end;
    poivt->next = doQuickSort(bigger.next, end);
    // 返回的是排序后的第一个链表节点
    return smaller.next;
  }
};