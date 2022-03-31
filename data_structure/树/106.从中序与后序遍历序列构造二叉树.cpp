/**
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */
class Solution {
 public:
  TreeNode* doBuild(vector<int>& inorder, int i, int j, vector<int>& postorder,
                    int s, int e) {
    if (i > j) return nullptr;
    auto rootNode = new TreeNode(postorder[e]);
    if (i == j) return rootNode;

    int n = i;
    for (; n <= j; n++) {
      if (inorder[n] == postorder[e]) break;
    }
    rootNode->left = doBuild(inorder, i, n - 1, postorder, s, s + n - i - 1);
    rootNode->right = doBuild(inorder, n + 1, j, postorder, s + n - i, e - 1);
    return rootNode;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return doBuild(inorder, 0, inorder.size() - 1, postorder, 0,
                   postorder.size() - 1);
  }
};