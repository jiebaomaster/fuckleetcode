/**
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/
 * 二叉树的右视图即二叉树“每一层上最右边的元素”
 * 
 * 方法一：二叉树的层序遍历
 */
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int cnt = q.size();
      for (int i = 0; i < cnt; i++) {
        auto n = q.front();
        q.pop();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        if (i == cnt - 1) { // 每一层只输出最后一个元素
          res.push_back(n->val);
        }
      }
    }
    return res;
  }
};

/**
 * 方法二：“根右左”的先序遍历
 */
class Solution1 {
 public:
  vector<int> res;
  vector<int> rightSideView(TreeNode* root) {
    doTravel(root, 1);
    return res;
  }
  /**
   * @param curDeepth 当前元素的深度
   */
  void doTravel(TreeNode* root, int curDeepth) {
    if (!root) return;
    /**
     * 当前元素的深度 大于 右边已被遮挡的元素深度 时可以输出。
     * 其中 右边已被遮挡的元素深度 等于 已输出的元素个数，因为
     * 每个输出的元素必定是所在行的最右边的元素
     */
    if (curDeepth > res.size()) res.push_back(root->val);
    // 先遍历右子树，保证右边的元素先被看到
    doTravel(root->right, curDeepth + 1);
    doTravel(root->left, curDeepth + 1);
  }
};