/**
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 借助栈的迭代写法
 */
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> st; // 暂存左子树的结点
    TreeNode* cur = root;
    while (cur || !st.empty()) {
      while (cur) { // 走到左下角
        st.push(cur);
        cur = cur->left;
      }
      // 访问栈顶
      cur = st.top();
      st.pop();
      ret.push_back(cur->val);

      // 如果有右子树，就走右子树，否则设为 null 从栈中弹出一个
      cur = cur->right;
    }

    return ret;
  }
};

/**
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-bian-li-fang-fa-da-quan-bao-han-mo-li-2/
 * 方法二：莫里斯遍历法
 * 莫里斯遍历不需要递归或者临时的栈空间就可以完成遍历，空间复杂度是常数。
 * 但是为了解决从子节点找到父节点的问题，需要临时修改树的结构，建立左子树
 * 中最右边节点到父节点的关系，在遍历完成之后复原成原来的树结构。
 * 
 * 时间复杂度分析：
 * 虽然有嵌套的循环，但是对于任意根节点来说，只会进行两次搜索前驱节点
 * 加上对自身的遍历，综合来说，树的每个节点的遍历次数最多是 3 次
 * 就 O(3n)
 */
class Solution {
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
          pre->right = cur;
          cur = cur->left;
        } else { // 已经建立过关系了，说明左子树都遍历完成了
          res.push_back(cur->val); // 左子树都遍历完成，可以输出根节点
          cur = cur->right; // 遍历右子树
          pre->right = nullptr; // 删除临时连接
        }
      }
    }
    return res;
  }
};