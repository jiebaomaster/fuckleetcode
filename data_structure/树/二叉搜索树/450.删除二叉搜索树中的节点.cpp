/**
 * https://leetcode.cn/problems/delete-node-in-a-bst/submissions/
 * 方法一：迭代法
 */
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    auto p = root;
    TreeNode head(-1);
    head.left = root;
    auto parent = &head;
    bool left = true;
    // 找到要删除的节点
    while (p && p->val != key) {
      parent = p;
      if (p->val > key) {
        p = p->left;
        left = true;
      } else {
        p = p->right;
        left = false;
      }
    }
    // 要删除的节点不存在，直接返回
    if (!p) return head.left;
    // 删除叶子结点
    if (!p->left && !p->right) {
      if (left)
        parent->left = nullptr;
      else
        parent->right = nullptr;
    } else if (!p->left || !p->right) { // 删除只有一边子树的节点
      auto child = p->left ? p->left : p->right;
      if (left)
        parent->left = child;
      else
        parent->right = child;
    } else { // 删除两边都有子树的节点
      auto n = p->left;
      parent = p;
      left = true;
      // 找前驱节点，左子树的最右边
      while (n->right) {
        parent = n;
        n = n->right;
        left = false;
      }
      // 将前驱节点的值保存在当前节点
      p->val = n->val;
      // 删除前驱节点
      if (!n->left && !n->right) {
        if (left)
          parent->left = nullptr;
        else
          parent->right = nullptr;
      } else {
        auto child = n->left ? n->left : n->right;
        if (left)
          parent->left = child;
        else
          parent->right = child;
      }
    }
    return head.left;
  }
};

/**
 * 方法二：递归
 */
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    } else {  // 删除当前节点
      if (!root->left && !root->right) {
        // 要删除的是叶子节点，可以直接删除
        delete root;
        return nullptr;
      } else if (!root->left || !root->right) {
        // 要删除的节点一边子树为空，可以直接用另一边子树替代当前节点
        auto n = root->left ? root->left : root->right;
        delete root;
        return n;
      } else {
        // 要删除的节点两边子树都不为空
        // 找到左子树的最小节点（或右子树的最小节点）
        auto n = root->left;
        while (n->right) {
          n = n->right;
        }
        // 要被删除的节点val设置为左子树的最小节点，简单替换
        root->val = n->val;
        // 在左子树中删除最大节点
        root->left = deleteNode(root->left, n->val);
        return root;
      }
    }
  }
};