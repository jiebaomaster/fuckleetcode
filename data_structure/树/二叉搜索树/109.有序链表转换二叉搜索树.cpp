/**
 * https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/
 * 要使构建出来的 BST 是平衡的，只要左右两边的子 BST 的元素个数之差不大于 1
 * 快慢指针找链表中点，然后递归构造左右两边的子 BST
 */
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) {
      return new TreeNode(head->val);
    }
    auto slow = head;
    auto fast = head;
    ListNode* pre = nullptr;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow 指向后一半的第一个，pre 指向前一半的最后一个
    auto root = new TreeNode(slow->val);
    // 断开前一半和后一半的，这样在递归构建左子 BST 时能正常退出
    pre->next = nullptr; 
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
  }
};