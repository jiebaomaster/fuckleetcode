/**
 * https://leetcode-cn.com/problems/sliding-puzzle/
 * https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw
 * 状态：board 是 2x3 的二维数组，可以压缩成一个一维字符串
 * 选择：每次移动，可表示为状态字符串中的 0 与其「上下左右」4 个相邻位置的数字做交换
 * 其中比较有技巧性的点在于，二维数组有「上下左右」的概念，压缩成一维后，
 * 如何得到某一个索引上下左右的索引？由于只有 6 个位置，可以直接写出来
 */
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    unordered_set<string> visited;
    queue<string> q;
    string target = "123450"; // 目标状态
    string start = "";
    for (auto& raw : board) { // 拼接初始状态
      for (int e : raw) {
        start += '0' + e;
      }
    }
    visited.insert(start);
    q.push(start);
    // 各索引相邻的索引
    vector<vector<int>> next = {
      {1, 3}, // 位置 0 的右、下
      {0, 2, 4}, // 位置 1 的左、右、下
      {1, 5},
      {0, 4}, 
      {1, 3, 5}, 
      {2, 4}
    };
    int step = 0;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i--) {
        string cur = q.front();
        q.pop();

        if (cur == target) return step;

        for (int j = 0; j < 6; j++) {
          // 将数字 0 和相邻的数字交换位置
          if (cur[j] == '0') {
            for (int k : next[j]) { // 所有相邻位置
              swap(cur[j], cur[k]); // 交换
              // 防止走回头路
              if (visited.find(cur) == visited.end()) {
                q.push(cur);
                visited.insert(cur);
              }
              swap(cur[j], cur[k]); // 恢复
            }
            break;
          }
        }
      }
      step++;
    }

    return -1;
  }
};