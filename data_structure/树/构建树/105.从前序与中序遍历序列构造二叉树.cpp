/**
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return doBuild(preorder, 0, preorder.size() - 1, inorder, 0,
                   inorder.size() - 1);
  }
  TreeNode* doBuild(vector<int>& preorder, int pre_s, int pre_e,
                    vector<int>& inorder, int in_s, int in_e) {
    if (pre_s > pre_e || in_s > in_e) return nullptr;
    // 先序遍历的第一个是根结点
    auto root = new TreeNode(preorder[pre_s]);
    // 在中序遍历中找根节点
    int i = in_s;
    for (; i < in_e; i++) {
      if (inorder[i] == root->val) break;
    }
    // 由根节点在中序遍历的位置将中序遍历分为前后两部分，分别对应左右子树
    int len = i - in_s; // 左子树的节点数
    // 递归构建左右子树
    root->left =
        doBuild(preorder, pre_s + 1, pre_s + len, inorder, in_s, i - 1);
    root->right =
        doBuild(preorder, pre_s + len + 1, pre_e, inorder, i + 1, in_e);

    return root;
  }
};