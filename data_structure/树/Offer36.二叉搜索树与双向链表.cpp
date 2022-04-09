/**
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 * 方法一：后序遍历
 */
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    auto n = inorder(root);
    // 生成循环链表
    n.first->left = n.second;
    n.second->right = n.first;
    return n.first;
  }
  // 后序遍历，处理当前节点和前后链表的关系
  // 返回当前链表的最大值和最小值
  pair<Node*, Node*> inorder(Node* root) {
    if (!root) return {nullptr, nullptr};
    auto left = inorder(root->left);
    auto right = inorder(root->right);
    pair<Node*, Node*> res = {root, root};
    if (left.first) { // 左节点存在的话，更新最小值
      left.second->right = root;
      root->left = left.second;
      res.first = left.first;
    }
    if (right.first) { // 右节点存在的话，更新最大值
      right.first->left = root;
      root->right = right.first;
      res.second = right.second;
    }

    return res;
  }
};

/**
 * 方法二：中序遍历+记录前一个节点
 */
class Solution1 {
 public:
  Node* treeToDoublyList(Node* root) {
    if (root == nullptr) return nullptr;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
  }

 private:
  Node *pre, // 记录已处理节点的前一个节点
      *head;
  // 中序遍历，处理当前节点与前一个节点的关系
  void dfs(Node* cur) {
    if (cur == nullptr) return;
    dfs(cur->left);

    // 构建链表
    if (pre != nullptr)
      pre->right = cur;
    else
      head = cur;
    cur->left = pre;
    pre = cur;

    dfs(cur->right);
  }
};

/**
 * 方法三：中序遍历的迭代写法
 */
class Solution2 {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    stack<Node*> stk;
    auto p = root;
    Node* pre = nullptr;
    Node* head = nullptr;
    while (!stk.empty() || p) {
      while (p) {
        stk.push(p);
        p = p->left;
      }
      p = stk.top();
      stk.pop();
      
      // 构建链表
      if (!pre)
        head = p;
      else
        pre->right = p;
      p->left = pre;
      pre = p;

      p = p->right;
    }
    head->left = pre;
    pre->right = head;
    return head;
  }
};