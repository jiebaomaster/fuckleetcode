/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 * 大数加法，链表结构
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1, *p2 = l2, *res_prev;
    int join = 0; // 保存进位，在下一位的运算中加上
    int tmp = 0;
    /* 1. 两条链都没走完，进行每位相加 */
    while (p1 && p2) {
      tmp = p1->val + p2->val + join;
      p1->val = tmp % 10; // 计算本位结果
      join = tmp / 10; // 计算本位进位

      res_prev = p1; // 默认复用 l1，下面会判断长度
      p1 = p1->next;
      p2 = p2->next;
    }

    /* 2. 其中一条链走完了，考虑进位对剩下数字的影响*/
    ListNode* p = nullptr;
    if (p1 || p2) {
      // 复用了更长的链表作为返回，需要判断哪条链更长
      if (p1) {
        p = p1;
      } else if (p2) {
        p = p2;
        res_prev->next = p;
      }
      while (p && join) {
        tmp = p->val + join;
        p->val = tmp % 10;
        join = tmp / 10;

        res_prev = p;
        p = p->next;
      }
    }
    /* 最后还有进位的话，只能新建一个节点了 */
    if (join) {
      p = new ListNode(join);
      res_prev->next = p;
    }

    return l1;
  }
};