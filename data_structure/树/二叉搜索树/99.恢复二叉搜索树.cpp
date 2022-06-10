/**
 * https://leetcode.cn/problems/recover-binary-search-tree/
 * 要在不改变 BST 结构的情况下恢复 BST，需要准确找到错位的两个节点
 * 根据 BST 中序遍历递增性，可得错位的节点将在遍历序列中造成逆序对
 * 1234567 ==交换47==> 1237564
 * 则第一逆序 75 的第一个节点 7 和第二逆序 64 的第二个节点 4 是错位节点
 */
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    dfs(root);
    swap(first->val, second->val);
  }

  TreeNode* pre; // 前序节点，比较逆序性
  TreeNode *first, *second; // 错位节点
  void dfs(TreeNode* root) {
    if (!root) return;

    dfs(root->left);
    if (pre) {
      if (pre->val > root->val) { // 找到逆序
        if (!first) {
          first = pre;
          second = root;
        } else {
          second = root;
        }
      }
    }
    pre = root; // 更新前序节点
    dfs(root->right);
  }
};

/**
 * 方法二：中序莫里斯遍历
 */
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    morris(root);
    swap(first->val, second->val);
  }

  TreeNode* prevNode;
  TreeNode *first, *second;
  void morris(TreeNode* root) {
    auto cur = root;
    while (cur) {
      if (!cur->left) {
        doTraverl(cur);
        cur = cur->right;  // rc or father
      } else {
        auto pre = cur->left;
        while (pre->right && pre->right != cur) pre = pre->right;

        if (pre->right) {  // used
          doTraverl(cur);
          cur = cur->right;  // rc or father
          pre->right = nullptr;
        } else {
          pre->right = cur;  // build right->cur
          cur = cur->left;   // lc
        }
      }
    }
  }

  void doTraverl(TreeNode* node) {
    if (prevNode) {
      if (prevNode->val > node->val) {
        second = node;
        if (!first) {
          first = prevNode;
        }
      }
    }
    prevNode = node;
  }
};