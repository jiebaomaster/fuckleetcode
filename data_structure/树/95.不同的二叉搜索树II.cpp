/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * 类似第 96 题，可通过枚举作为根节点的元素生成二叉搜索树
 */
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n <= 0)
      return {};
    else
      return doGenerate(1, n);
  }

  vector<TreeNode*> doGenerate(int l, int r) {
    if (l > r) {
      return {nullptr};
    }

    vector<TreeNode*> res;
    // 枚举作为根节点的元素
    for (int root = l; root <= r; root++) {
      // 生成左右子树
      auto leftTrees = doGenerate(l, root - 1);
      auto rightTrees = doGenerate(root + 1, r);
      // 左右子树做组合，每种组合加上根节点就是一棵完整的树
      for (auto leftNode : leftTrees) {
        for (auto rightNode : rightTrees) {
          auto rootNode = new TreeNode(root);
          rootNode->left = leftNode;
          rootNode->right = rightNode;
          res.push_back(rootNode);
        }
      }
    }
    return res;
  }
};