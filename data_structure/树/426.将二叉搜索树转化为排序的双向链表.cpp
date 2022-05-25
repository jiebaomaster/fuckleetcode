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
  // 展开为双向链表
  Node* doTreeToDoublyList(Node* root) {
    if (!root) return nullptr;

    Node* ln = nullptr;
    if (root->left) {
      ln = treeToDoublyList(root->left);
      prev->right = root;
      root->left = prev;
    }
    // 中序遍历，保证 prev 始终指向前驱节点
    prev = root;
    if (root->right) {
      auto rn = treeToDoublyList(root->right);
      root->right = rn;
      rn->left = root;
    }
    // 返回最左边的点
    return ln ? ln : root;
  }
};