/**
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * 后序遍历的迭代写法，关键在于判断右子树是否已被访问过
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st; // 暂存左子树的结点
    auto p = root;
    TreeNode* pre = nullptr;
    while (p || !st.empty()) {
      while (p) { // 走到左下角
        st.push(p);
        p = p->left;
      }
      p = st.top();
      // 右子树不存在 或者 右子树已经被遍历过，则访问根结点
      if (!p->right || p->right == pre) {
        res.push_back(p->val);
        st.pop(); // 访问过之后才能出栈
        pre = p; // 记录结点的访问情况，在返回上层时判断右结点是否已经访问过
        p = nullptr; // 右子树不存在，返回上层
      } else { // 走右子树
        p = p->right;
      }
    }
    return res;
  }
};

/**
 * 后序遍历的性质：后序遍历可以通过前序遍历得到，按“父右左”的顺序遍历，然后反转结果
 * 相应地，可以通过修改前序遍历的代码得到后序遍历的代码：
 *   把原来的所有的right改成left，原来的left改成right
 *   最后添加一步结果反转
 * 
 * 方法二：父右左迭代+翻转
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    auto p = root;
    while (p || !s.empty()) {
      while (p) {
        res.push_back(p->val);
        s.push(p);
        p = p->right;
      }

      p = s.top();
      s.pop();
      p = p->left;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

/**
 * 方法三：“父右左”莫里斯前序遍历+翻转
 *   和方法二一样，修改前序莫里斯遍历的代码得到后序莫里斯遍历的代码
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    auto cur = root;
    while (cur) {
      if (!cur->right) {
        res.push_back(cur->val);
        cur = cur->left;
      } else {
        auto pre = cur->right;
        while (pre->left && pre->left != cur) pre = pre->left;

        if (!pre->left) {
          res.push_back(cur->val);
          pre->left = cur;
          cur = cur->right;
        } else {
          cur = cur->left;
          pre->left = nullptr;
        }
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
