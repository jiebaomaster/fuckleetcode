/**
 * https://leetcode-cn.com/problems/linked-list-random-node/
 * https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/
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
  ListNode* head_;

 public:
  Solution(ListNode* head) { head_ = head; }

  int getRandom() {
    ListNode* node = head_;
    int count = 1;
    int ret;
    while (node) {
      // 一个随机数可以被 count 整除的概率是 1/count
      // 1/count 的概率选中当前节点
      if (rand() % count == 0) {
        ret = node->val;
      }
      count++;
      node = node->next;
    }
    return ret;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */