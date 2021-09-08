/**
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/shuang-zhi-zhen-ji-qiao#yi-kuai-man-zhi-zhen-de-chang-jian-suan-fa
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 快慢指针，让快指针先走n步，再同步走，直到快指针走到最后一个节点，此时慢指针指向要删除的前一个节点，
 * 1. 由于有可能要删除最后一个节点，所以不使用链表本地删除法
 * 2. 要特殊考虑删除第一个节点的情况
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || n < 0) return nullptr;

    ListNode *fast = head, *slow = head;
    while (n--) { // 让快指针先走 n 步
      fast = fast->next;
      if (fast == nullptr) {
        if (n > 0)  // 要删除的不在链表内，报错
          return nullptr;
        else {  // 此时 n==0，删除链表第一个节点，返回首节点的后一个节点即可
          return head->next;
        }
      }
    }
    // 同步走，直到快指针走到最后一个节点，此时慢指针指向要删除的前一个节点
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    // 删除 slow 的后面一个
    slow->next = slow->next->next;
    return head;
  }
};