/**
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 * 思路还是相同的，找根节点，划分左右子树，递归构建
 * 不同的是，只有每个节点度为2或者0的时候前序和后序才能唯一确定一颗二叉树，
 * 只有一个子节点是无法确定的，因为你无法判断他是左子树还是右子树
 */
class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    return doConstruct(preorder, 0, preorder.size() - 1, postorder, 0,
                       postorder.size() - 1);
  }

  TreeNode* doConstruct(vector<int>& preorder, int pre_l, int pre_r,
                        vector<int>& postorder, int post_l, int post_r) {
    if (pre_l > pre_r) return nullptr;
    auto newNode = new TreeNode(preorder[pre_l]);
    if (pre_l == pre_r) return newNode;

    // pre[pre_l + 1] 是左子树的根节点，左子树的根节点必定出现在post 中左子树遍历的最后面
    // 以此求出左子树的节点个数，划分左右子树区间
    // 
    int left_root = 0;
    while (preorder[pre_l + 1] != postorder[left_root]) left_root++;
    int left_cnt = left_root - post_l + 1;

    newNode->left = doConstruct(preorder, pre_l + 1, pre_l + left_cnt,
                                postorder, post_l, left_root);
    newNode->right = doConstruct(preorder, pre_l + left_cnt + 1, pre_r,
                                 postorder, left_root + 1, post_r - 1);

    return newNode;
  }
};