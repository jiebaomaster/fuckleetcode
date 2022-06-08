/**
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
 * 方法一：层序遍历
 * 在每一层中建立 next 指针的关系
 */
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();
        if (i > 1)  // 层中
          n->next = q.front();
        else  // 到达层尾
          n->next = nullptr;
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
    }
    return root;
  }
};

/**
 * 方法二：遍历每一层的链表
 * 同一层的节点已经记录在链表中了，不需要用一个队列记录，省去额外的空间
 */
class Solution {
 public:
  Node* connect(Node* root) {
    Node* cur = root;
    Node* first = root; // 下一层的第一个节点
    while (first) { // 遍历每一层
      Node hair(-1); // 下一层链表的虚拟头节点
      Node* pre = &hair;
      cur = first;
      while (cur) { // 遍历本层，构建下一层的链表
        if (cur->left) { // 链接左孩子
          pre->next = cur->left;
          pre = pre->next;
        }
        if (cur->right) { // 链接右孩子
          pre->next = cur->right;
          pre = pre->next;
        }
        cur = cur->next;
      }
      // 本层遍历完了，更新下一层的第一个节点
      first = hair.next;
    }
    return root;
  }
};