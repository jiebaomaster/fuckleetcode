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

/**
 * 技巧：在操作链表时，可能需要知道待操作元素的前一个元素，而待操作元素可能是头结点
 * 其前一个元素不存在，需要特殊处理，此时可以创建一个假的头结点，这样头节点也有前一个
 * 元素了，可以统一处理，注意最后返回结果时需返回真的头节点即 fakeHead.next
 */
class Solution1 {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode fakeHead(0); // 创建一个假的头结点，统一处理所有情况
    fakeHead.next = head;
    ListNode* slow = &fakeHead;
    ListNode* fast = head;
    while (n--) {
      fast = fast->next;
    }
    // 同步走，直到快指针走到最后一个节点
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }

    // 此时 slow 指向 目标的前一个结点
    slow->next = slow->next->next;
    return fakeHead.next;
  }
};