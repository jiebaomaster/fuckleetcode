/**
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/shuang-zhi-zhen-ji-qiao#yi-kuai-man-zhi-zhen-de-chang-jian-suan-fa
 *
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) return nullptr;
    // 1. 判断是否有环
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {  // 有环
        // 2. 计算环的大小，slow走环一圈，双指针再次相遇代表走完一圈
        int count = 0;
        do {
          slow = slow->next;
          count++;
        } while (slow != fast);
        // 3. 从头开始，fast先走count步，则双指针会相遇在环的入口节点处
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
 * 方法二：简单走法
 * s = a+b
 * f = a+b+k(b+c)
 * f = 2s = 2(a+b)
 * a+b+k(b+c) = 2(a+b)
 * a+b = k(b+c)
 * a = k(b+c) - b = c + (k-1)(b+c)
 * 
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto s = head;
    auto f = head;
    while (f && f->next) {
      f = f->next->next;
      s = s->next;
      if (f == s) {
        s = head; // s 从起点开始，一定在环的入口处相遇
        while (s != f) {
          s = s->next;
          f = f->next;
        }
        return s;
      }
    }

    return nullptr;
  }
};