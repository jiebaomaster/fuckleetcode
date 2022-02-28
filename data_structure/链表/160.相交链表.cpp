/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * 找出并返回两个单链表相交的起始节点
 * _ _ _ _
 *         > - - -
 * - - - -
 * 方法一：
 * 先遍历计算两个两个链表的长度差 diff，快慢指针，较长链表的指针先走 diff 步，
 * 接着两个指针一起走，相遇的第一个就是起始交点
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int countA = 0, countB = 0;
    ListNode *pA = headA, *pB = headB;
    // 先遍历计算两个两个链表的长度差diff
    while (pA) {
      pA = pA->next;
      countA++;
    }
    while (pB) {
      pB = pB->next;
      countB++;
    }

    pA = headA;
    pB = headB;
    int diff = countA - countB;
    if (diff < 0) {
      swap(pA, pB);
      diff = countB - countA;
    }
    // 较长链表的先走diff步
    while (diff--) {
      pA = pA->next;
    }
    while (pA && pB) {
      if (pA == pB) {
        return pA;
      }
      pA = pA->next;
      pB = pB->next;
    }
    return nullptr;
  }
};

/**
 * 方法二：
 * 可以先将其中一个链表的首尾相接，此时另一个链表成为存在循环的链表，
 * 从另一个链表开始遍历，题目转化为寻找循环开始的那个结点，题 142
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;

    ListNode *pA = headA, *pB = headB;
    while (pA->next) {
      pA = pA->next;
    }
    pA->next = headA;
    auto ret = detectCycle(pB);
    pA->next = nullptr;
    return ret;
  }
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) return nullptr;
    // 判断是否有环
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {  // 有环
        // 计算环的大小，slow走环一圈，双指针再次相遇代表走完一圈
        int count = 0;
        do {
          slow = slow->next;
          count++;
        } while (slow != fast);
        // 从头开始，fast先走count步，则双指针会相遇在环的入口节点处
        slow = fast = head;
        while (count--) {
          fast = fast->next;
        }
        while (slow != fast) {
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      };
    }
    return nullptr;
  }
};

/**
 * 方法三：
 * 用一个 set 存储 listA，再遍历 listB，看 set 中是否存在
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> nodes;
    while (headA) {
      nodes.insert(headA);
      headA = headA->next;
    }
    while (headB) {
      if (nodes.find(headB) != nodes.end()) {
        return headB;
      }
      headB = headB->next;
    }
    return nullptr;
  }
};