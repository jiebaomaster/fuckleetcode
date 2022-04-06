/**
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 * 方法一：使用 hash 表存储对应的链表节点
 */
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> f_c;
    auto p = head;
    Node hair(-1);
    auto pre = &hair;
    // 先复制单链表，并将对应节点存入 hash 表
    while (p) {
      auto n = new Node(p->val);
      pre->next = n;
      f_c.insert({p, n});
      pre = n;
      p = p->next;
    }
    p = head;
    auto cur = hair.next;
    // 使用hash表的对应关系构建复制链表的 random 指针
    while (p) {
      cur->random = f_c[p->random];
      p = p->next;
      cur = cur->next;
    }
    return hair.next;
  }
};

/**
 * 方法二：原地插入复制，利用复制节点的相邻关系替代 hash 表
 */
class Solution1 {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    // 将复制节点插入源节点的后面
    for (auto p = head; p != nullptr; p = p->next->next) {
      auto n = new Node(p->val);
      n->next = p->next;
      p->next = n;
    }
    // 构建 random，复制节点的 random 是源节点 random 的后面一个
    auto target = head->next;
    for (auto p = head; p != nullptr; p = p->next->next) {
      p->next->random = p->random ? p->random->next : nullptr;
    }
    // 分离源链表和复制链表
    for (auto p = head, pp = head->next; p != nullptr;
         p = p->next, pp = pp->next) {
      p->next = pp->next;
      pp->next = pp->next ? pp->next->next : nullptr;
    }
    return target;
  }
};