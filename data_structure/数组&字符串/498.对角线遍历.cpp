/**
 * https://leetcode-cn.com/problems/diagonal-traverse/
 * 方法一：mat[0][0] 为根节点的层序遍历，左子树为 [i+1, j]，右子树为 [i,j+1]
 * 类似 103 题，二叉树的锯齿形遍历，区别在于需要加一个 used 防止子节点重复入队
 */
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> res;
    vector<vector<bool>> used(n, vector<bool>(m, false));
    deque<pair<int, int>> q;
    vector<int> level;
    q.push_back({0, 0});
    bool up = true;  // 是否从下往上遍历
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i--) {
        if (up) {
          auto node = q.front();
          q.pop_front();
          res.push_back(mat[node.first][node.second]);
          if (isValid(make_pair(node.first + 1, node.second), n, m, used)) {
            q.push_back({node.first + 1, node.second});
            used[node.first + 1][node.second] = true;
          }
          if (isValid(make_pair(node.first, node.second + 1), n, m, used)) {
            q.push_back({node.first, node.second + 1});
            used[node.first][node.second + 1] = true;
          }
        } else {
          auto node = q.back();
          q.pop_back();
          res.push_back(mat[node.first][node.second]);
          if (isValid(make_pair(node.first, node.second + 1), n, m, used)) {
            q.push_front({node.first, node.second + 1});
            used[node.first][node.second + 1] = true;
          }
          if (isValid(make_pair(node.first + 1, node.second), n, m, used)) {
            q.push_front({node.first + 1, node.second});
            used[node.first + 1][node.second] = true;
          }
        }
      }
      up = !up;
    }
    return res;
  }
  bool isValid(pair<int, int> node, int n, int m, vector<vector<bool>>& used) {
    return node.first >= 0 && node.first < n && node.second >= 0 &&
           node.second < m && !used[node.first][node.second];
  }
};

/**
 * https://leetcode-cn.com/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-fen-xi-ti-mu-zhao-zhun-gui-l/
 * 方法二：直接模拟
 * 每一趟对角线中元素的坐标（x, y）相加的和是递增的。
 * 且一条对角线中的 xi+yi 恒定
 */
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> res;
    int i = 0; // i 是 x + y 的和
    while (i < m + n) {
      // up
      // 确定 x y 的初始值
      int x1 = i < n ? i : n - 1;
      int y1 = i - x1;
      while (x1 >= 0 && y1 < m) {
        res.push_back(mat[x1][y1]);
        x1--;
        y1++;
      }
      i++;

      if (i >= m + n) break;
      // down
      // 确定 x y 的初始值
      int x2 = i < m ? 0 : i - (m - 1);
      int y2 = i - x2;
      while (y2 >= 0 && x2 < n) {
        res.push_back(mat[x2][y2]);
        x2++;
        y2--;
      }
      i++;
    }

    return res;
  }
};