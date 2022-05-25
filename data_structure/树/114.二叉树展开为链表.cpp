/**
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 * 
 * 方法一：递归后序遍历的同时展开
 */
class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root) return;
    doFlatten(root);
  }
  /**
   * @brief 展开 node 树，返回展开后的最后一个节点
   */
  TreeNode* doFlatten(TreeNode* node) {
    if (!node->left && !node->right) {
      return node;
    } else if (node->left && node->right) {
      auto l = doFlatten(node->left);
      auto r = doFlatten(node->right);
      l->right = node->right;
      node->right = node->left;
      node->left = nullptr;
      return r;
    } else if (node->left) {
      auto l = doFlatten(node->left);
      node->right = node->left;
      node->left = nullptr;
      return l;
    } else {
      auto r = doFlatten(node->right);
      return r;
    }
  }
};

/**
 * 方法二：莫里斯遍历，在左子树处理完之后，处理当前节点的展开
 */
class Solution {
 public:
  void flatten(TreeNode* root) {
    auto cur = root;
    while (cur) {
      if (!cur->left) { // 没有左节点，不用处理，走向右节点
        cur = cur->right;
      } else {
        auto pre = cur->left;
        while (pre->right && pre->right != cur)
          pre = pre->right;

        if (!pre->right) { // 构建前驱节点关系
          pre->right = cur;
          cur = cur->left; // 处理左子树
        } else { // 左子树处理完了，处理当前节点的展开
          pre->right = cur->right; // 左子树的最右边节点->右子树
          cur->right = cur->left; // cur->左子树
          cur->left = nullptr;
          cur = pre->right; // 处理右子树
        }
      }
    }
  }
};

/**
 * 方法三：记录后继节点
 */
class Solution {
 public:
  TreeNode* next; // 记录上一个遍历的节点
  void flatten(TreeNode* root) {
    if (!root) return;
    // 右->左->根，这样 next 总是指向后继节点
    flatten(root->right);
    flatten(root->left);

    root->right = next;
    root->left = nullptr;
    next = root;
    return;
  }
};
