/**
 * https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
 * 与 572 题大致思路相同，细节不同
 * 本题是判断一棵树是否是另一颗树的子结构，子结构不需要树完全相等
 */
class Solution {
 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!B || !A) return false;

    return isSub(A, B) // 判断自身
    || isSubStructure(A->left, B) // 判断左子树
    ||isSubStructure(A->right, B); // 判断右子树
  }
  // 判断 b 是否是 a 的子结构
  bool isSub(TreeNode* a, TreeNode* b) {
    if (!b) return true; // 空树一定是另一棵树的子结构
    if (!a) return false; // 空树本身不存在子结构
    // 左右子树都要是子结构
    return a->val == b->val && isSub(a->left, b->left) &&
           isSub(a->right, b->right);
  }
};

/**
 * 方法二：层序遍历判断子结构
 */
class Solution {
 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!B || !A) return false;

    return isSame(A, B) || isSubStructure(A->left, B) ||
           isSubStructure(A->right, B);
  }
  bool isSame(TreeNode* a, TreeNode* b) {
    queue<TreeNode*> q;
    q.push(a);
    q.push(b);
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i -= 2) {
        auto aa = q.front();
        q.pop();
        auto bb = q.front();
        q.pop();
        if (!bb) continue;
        if (!aa) return false;
        if (aa->val != bb->val) return false;

        q.push(aa->left);
        q.push(bb->left);
        q.push(aa->right);
        q.push(bb->right);
      }
    }
    return true;
  }
};