/*
 * https://leetcode.cn/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
 */
class Solution {
 public:
  Node* prev;
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    prev = nullptr;
    auto n = doTreeToDoublyList(root);
    // 构建循环链表
    n->left = prev;
    prev->right = n;
    return n;
  }
  // 中序遍历，展开为双向链表
  Node* doTreeToDoublyList(Node* root) {
    if (!root) return nullptr;
    
    // 展开左边
    auto l = doTreeToDoublyList(root->left);
    
    // 处理当前
    if (pre) {
      pre->right = root;
      root->left = pre;
      pre = root;
    } else // pre 不存在，即左下角
      pre = root;

    // 展开右边
    doTreeToDoublyList(root->right);

    // 返回最左边的点
    return l ? l : root;
  }
};