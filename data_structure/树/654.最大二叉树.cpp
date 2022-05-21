/**
 * https://leetcode.cn/problems/maximum-binary-tree/
 * 递归生成二叉树
 */
class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfs(nums.begin(), nums.end());
  }
  TreeNode* dfs(vector<int>::iterator l, vector<int>::iterator r) {
    if (l >= r) return nullptr;

    auto rootIter = max_element(l, r); // [l, r) 内的最大值作为根
    auto rootNode = new TreeNode(*rootIter);
    rootNode->left = dfs(l, rootIter);
    rootNode->right = dfs(rootIter + 1, r);
    return rootNode;
  }
};