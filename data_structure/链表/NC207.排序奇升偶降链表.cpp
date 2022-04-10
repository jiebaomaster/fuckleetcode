/**
 * https://www.nowcoder.com/practice/3a188e9c06ce4844b031713b82784a2a?tpId=117&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=&judgeStatus=&tags=&title=207&gioEnter=menu
 *
 * 链表的奇数节点升序，偶数节点降序，重排序成有序链表
 * 例如 {1,3,2,2,3,1} => {1,1,2,2,3,3}
 *
 * 分成三步：分离奇偶链表；翻转偶链表，使偶链表升序；合并两个有序链表
 */
class Solution {
 public:
  ListNode* sortLinkedList(ListNode* head) {
    // split
    ListNode odd(-1);
    ListNode even(-1);
    auto oddpre = &odd;
    auto evenpre = &even;
    auto p = head;
    bool isOdd = true;
    while (p) {
      if (isOdd) {
        oddpre->next = p;
        oddpre = p;
        p = p->next;
        oddpre->next = nullptr;
      } else {
        evenpre->next = p;
        evenpre = p;
        p = p->next;
        evenpre->next = nullptr;
      }
      isOdd = !isOdd;
    }

    // reverse
    evenpre = nullptr;
    p = even.next;
    while (p) {
      auto next = p->next;
      p->next = evenpre;
      evenpre = p;
      p = next;
    }
    even.next = evenpre;

    // merge
    ListNode hair(-1);
    auto pre = &hair;
    p = odd.next;
    auto q = even.next;
    while (p && q) {
      if (p->val > q->val) {
        pre->next = q;
        pre = q;
        q = q->next;
      } else {
        pre->next = p;
        pre = p;
        p = p->next;
      }
    }
    if (p) pre->next = p;
    if (q) pre->next = q;
    return hair.next;
  }
};

/**
 * 在分离奇偶链表时对偶链表使用头插法，保证偶链表升序，可以省去翻转偶链表这一步
 */
class Solution {
 public:
  ListNode* sortLinkedList(ListNode* head) {
    // split
    ListNode odd(-1);
    ListNode even(-1);
    auto oddpre = &odd;
    auto evenpre = &even;
    auto p = head;
    bool isOdd = true;
    while (p) {
      if (isOdd) {  // 奇链表使用尾插法
        oddpre->next = p;
        oddpre = p;
        p = p->next;
        oddpre->next = nullptr;
      } else {  // 对偶链表使用头插法，保证偶链表升序
        auto next = p->next;
        p->next = even.next;
        even.next = p;
        p = next;
      }
      isOdd = !isOdd;
    }

    // merge
    ListNode hair(-1);
    auto pre = &hair;
    p = odd.next;
    auto q = even.next;
    while (p && q) {
      if (p->val > q->val) {
        pre->next = q;
        pre = q;
        q = q->next;
      } else {
        pre->next = p;
        pre = p;
        p = p->next;
      }
    }
    if (p) pre->next = p;
    if (q) pre->next = q;
    return hair.next;
  }
};