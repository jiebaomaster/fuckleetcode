/**
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 * 方法一：构建 bst
 * bst 的中序遍历结果是固定递增的，判断能否由中序和后序构建成树
 */
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    vector<int> inorder(postorder.begin(), postorder.end());
    // bst 的中序遍历结果是固定递增的
    sort(inorder.begin(), inorder.end());

    return dfs(postorder, 0, postorder.size(), inorder, 0, inorder.size());
  }

  bool dfs(vector<int>& postorder, int lp, int rp, vector<int>& inorder, int li,
           int ri) {
    if (lp == rp || li == ri) return true;
    // root 是后序遍历的最后一个
    int root = postorder[rp - 1];
    // 在中序中找 root
    auto iter = lower_bound(inorder.begin() + li, inorder.begin() + ri, root);
    // 如果找不到 root，说明不能构建
    if (iter == inorder.begin() + ri || *iter != root) return false;
    // 递归构建子树
    int index = distance(inorder.begin(), iter);
    return dfs(postorder, lp, lp + (index - li), inorder, li, index) &&
           dfs(postorder, lp + (index - li), rp - 1, inorder, index + 1, ri);
  }
};

/**
 * 方法二：bst 的性质，左子树 < root 且 右子树 > root
 */
class Solution1 {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    return dfs(postorder, 0, postorder.size() - 1);
  }

  bool dfs(vector<int>& postorder, int l, int r) {
    if (l >= r) return true;

    int root = postorder[r];

    int p = l;
    // 找到第一个大于 root 的，即右子树的第一个节点
    // 保证左子树，判断右子树合法性
    while (postorder[p] < root) p++;
    int c = p; // c 为右子树的第一个节点
    // 判断右子树上的所有节点是否都大于 root
    while (postorder[p] > root) p++;
    // p 指向第一个不大于 root 的节点
    if (p != r) return false;
    // 递归判断左右子树
    return dfs(postorder, l, c - 1) && dfs(postorder, c, r - 1);
  }
};

/**
 * 方法三：单调栈
 * 从后往前遍历，根->右->左
 * 用单调栈保存根和右子树，栈低为根
 */
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    // 单调递增的单调栈
    stack<int> s;
    int root = INT_MAX;
    for (int i = postorder.size() - 1; i >= 0; i--) {
      // 左子树元素必须要小于 根节点，否则就不是二叉搜索树
      if (postorder[i] > root) {
        return false;
      }

      while (!s.empty() && postorder[i] < s.top()) {
        // 数组元素小于单调栈的元素了，表示当前节点是某个左子树的节点，记录下上个根节点
        // 找到这个左子树对应的根节点，之前右子树全部弹出，不再记录，因为不可能在往根节点的右子树走了
        root = s.top();
        s.pop();
      }
      // 此时 root 指向以 postorder[i] 为左子树的根节点
      // 接下去遍历的元素都应该是 root 的左子树上的节点

      // 这个新元素入栈
      s.push(postorder[i]);
    }
    return true;
  }
};