/**
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
 * 生成平衡的二叉搜索树，只需要找到平衡的根结点，即中点
 */
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
  }
  TreeNode* dfs(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return new TreeNode(nums[l]);

    // 中点作为根节点，保证平衡
    int mid = l + (r - l) / 2;
    auto root = new TreeNode(nums[mid]);
    // 递归生成子树
    root->left = dfs(nums, l, mid - 1);
    root->right = dfs(nums, mid + 1, r);
    return root;
  }
};