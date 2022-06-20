/**
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
 * 方法一：中序遍历 BST 得到有序数组，再比较前后元素之差
 */
class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);

    int res = INT_MAX;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] < res) {
        res = nums[i] - nums[i - 1];
        if (res == 0) return 0;
      }
    }
    return res;
  }

  void inorder(TreeNode* root, vector<int>& nums) {
    if (!root) return;

    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }
};

/**
 * 方法二：记录前序元素 pre，并在中序遍历时计算前后元素之差
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        res = INT_MAX;
        pre = nullptr;
        inorder(root);
        
        return res;
    }
    TreeNode* pre;
    int res;
    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);
        if(pre) {
            res = min(res, root->val - pre->val);
        }
        pre = root;
        inorder(root->right);
    }
};