/**
 * 在一个 n*m 的矩阵中，求从 start 走到 end 且不经过 lake 的最短路径条数
 * 注意本题要求出最短路径条数，故不能设置 used 数组防止走回头路，因为多条
 * 最短路径可能经过同一个结点到达终点。只要在到达终点时推出 bfs 就行了
 */
#include <stdio.h>

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> graph(n, vector<int>(m, 0));
  int start[2] = {0, 0};
  int end[2] = {0, 0};
  scanf("%d %d", &start[0], &start[1]);
  scanf("%d %d", &end[0], &end[1]);
  graph[end[0]][end[1]] = 2;

  // 输入 lake
  int lakeN = 0;
  scanf("%d", &lakeN);
  int lake[2] = {0};
  while (lakeN--) {
    scanf("%d %d", lake, &lake[1]);
    graph[lake[0]][lake[1]] = 1;
  }

  queue<pair<int, int>> q;
  int depth = 0;
  int cnt = 0;
  q.push({start[0], start[1]});
  bool got = false;  // 标记是否到达终点
  // 上下左右
  int mover[] = {-1, 1, 0, 0};
  int movec[] = {0, 0, -1, 1};
  while (!q.empty()) {  // 层序遍历
    depth++;
    for (int i = q.size(); i > 0; i--) {
      pair<int, int> node = q.front();
      q.pop();
      for (int j = 0; j < 4; j++) {  // 遍历上下左右四个方向的子节点
        pair<int, int> c = {node.first + mover[j], node.second + movec[j]};
        if (c.first >= 0 && c.first < n &&    // 行标合法
            c.second >= 0 && c.second < m) {  // 列标合法
          // 本结点的下一步走到了终点，记录最短路径的条数
          if (graph[c.first][c.second] == 2) {
            cnt++;
            got = true; // 标记已经到达，可以在这层遍历后退出
          } else if (graph[c.first][c.second] == 0) {
            q.push(c);
          }
        }
      }
    }
    if (got) {
      break;
    }
  }
  printf("%d %d", cnt, depth);
  return 0;
}