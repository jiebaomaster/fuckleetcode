/**
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * 方法一：递归
 */
class Solution {
 public:
  vector<int> res;
  vector<int> preorderTraversal(TreeNode* root) {
    doTraversal(root);
    return res;
  }
  void doTraversal(TreeNode* root) {
    if (!root) return;

    res.push_back(root->val);
    doTraversal(root->left);
    doTraversal(root->right);
  }
};

/**
 * 方法二：迭代
 */
class Solution1 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    auto p = root;
    stack<TreeNode*> s; // 暂存左子树的结点
    while (p || !s.empty()) {
      while (p) { // 依次访问左子树，直到左下角
        res.push_back(p->val);
        s.push(p);
        p = p->left;
      }
      // 访问左子树最下层结点的右子树
      p = s.top()->right;
      s.pop();
    }
    return res;
  }
};

/**
 * 方法三：莫里斯遍历
 * 和中序莫里斯遍历的代码类似，只是输出根节点的地方变了 
 */
class Solution2 {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    auto cur = root;
    while (cur) {
      if (!cur->left) { // 没有左子树
        res.push_back(cur->val); // 没有左子树的直接输出根节点
        cur = cur->right; // 遍历右子树
      } else { // 否则遍历左子树
        auto pre = cur->left;
        // 找到左子树的最右边节点 rightInleft，即搜索前驱节点
        while (pre->right && pre->right != cur) pre = pre->right;

        if (!pre->right) { // 建立 rightInleft 和 cur 的关系
          res.push_back(cur->val); // 前序遍历在将根节点向左子树移动前输出
          pre->right = cur;
          cur = cur->left;
        } else { // 已经建立过关系了，说明左子树都遍历完成了
          cur = cur->right; // 遍历右子树
          pre->right = nullptr; // 删除临时连接
        }
      }
    }
    return res;
  }
};