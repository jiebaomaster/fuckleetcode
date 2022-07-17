/**
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode fakeHead(0); // 新建假头结点处理要删除头结点的情况
    fakeHead.next = head;
    ListNode* pre = &fakeHead; // 待删除的前一个元素
    ListNode* cur = head;

    while (cur && cur->next) {
      // 如果当前结点是要删除的，找到最后一个值相等的要删除的元素
      if (cur->val == cur->next->val) {
        while (cur->next && cur->val == cur->next->val) {
          cur = cur->next;
        }
        // 删除重复元素
        pre->next = cur->next;
      } else // 不用删除，pre和cur都后移
        pre = cur;
      cur = cur->next;
    }
    return fakeHead.next;
  }
};

/**
 * 方法二：递归
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    if (head->val == head->next->val) {
      while (head->next && head->val == head->next->val) {
        head = head->next;
      }
      head = head->next;
      return deleteDuplicates(head);
    } else {
      head->next = deleteDuplicates(head->next);
      return head;
    }
  }
};