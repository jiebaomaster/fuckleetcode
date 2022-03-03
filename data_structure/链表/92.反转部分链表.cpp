/**
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * 方法一：直接反转，参考题 206，先找到要翻转的区域
 * 
 * 处理链表问题有个技巧是如果返回的头结点不能直接确定，可以创建假的头结点，
 * 则返回的头结点始终是 fakehead.next
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode fakehead(0); // 创建假的头结点
        fakehead.next  = head;
        ListNode* listPrev = &fakehead;
        ListNode* cur = head;
        // 找到待反转区域的上一个结点，用在最后链接反转后的链表
        for(int i = 1; i < left; i++) {
            listPrev = cur;
            cur = cur->next;
        }
        /**
         * 反转
         *               [    待反转区域          ]
         *  O  ->  O  ->  O  ->  O  ->  O ->  O  -> ...
         *     listPrev  prev   cur    next
         */
        ListNode* pre = cur;
        cur = cur->next;
        for(int i = left; i < right; i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 当前 pre 指向待反转链表的最后一个结点
        listPrev->next->next = cur; // end
        listPrev->next = pre; // start
        
        return fakehead.next;
    }
};

/**
 * 方法二：头插法
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode fakehead(0);
        fakehead.next  = head;
        ListNode* listPrev = &fakehead;
        ListNode* cur = head;
        
        for(int i = 1; i < left; i++) {
            listPrev = cur;
            cur = cur->next;
        }
        // 
        /**
         * 将 next 插入待反转区域的头部，即 listPrev 后面
         *               [    待反转区域          ]
         *  O  ->  O  ->  O  ->  O  ->  O ->  O  -> ...
         *     listPrev  cur    next
         */
        for(int i = left; i < right; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = listPrev->next;
            listPrev->next = next;
        }
        return fakehead.next;
    }
};