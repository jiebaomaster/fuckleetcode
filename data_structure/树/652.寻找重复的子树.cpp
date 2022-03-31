/**
 * https://leetcode-cn.com/problems/find-duplicate-subtrees/
 * 在一棵树中寻找是否有重复的子树，序列化每一棵子树，并 hash 序列化后的字符串，
 * 如果有字符串重复，则有子树重复
 */
class Solution {
 public:
  unordered_map<string, int> times; // 序列化字符串出现的次数
  vector<TreeNode*> ret;

  string seq(TreeNode* root) {
    if (root == nullptr) return "null";
    string res = to_string(root->val);
    string left = seq(root->left);
    string right = seq(root->right);
    res += "," + left + "," + right;
    if (times[res]++ == 1) {
      ret.push_back(root);
    }
    return res;
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    seq(root);
    return ret;
  }
};



