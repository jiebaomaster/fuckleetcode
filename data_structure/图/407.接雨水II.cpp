/**
 * https://leetcode.cn/problems/trapping-rain-water-ii/
 * https://leetcode.cn/problems/trapping-rain-water-ii/solution/bfsxiao-gen-dui-by-flycumt-lz6n/
 * 二维图中接雨水
 * 从边界开始，向内扩展，
 * 
 * 根据木桶原理，接水多少取决于最短的那根柱子，因此使用小根堆存放坐标和高度并按高度排序，
 * 先把最外边一圈四条边上的点放入小根堆队列并标记为已访问，然后开始向内BFS搜索，只要队列不为空，
 * 就每次弹出当前堆顶，它是外面一圈中的最小值，记为lowest，然后看一下它的四个邻居的格子，能不
 * 能往里灌水，如果邻居未越界且未访问过，就看邻居是否比lowest还矮，如果邻居格子比lowest矮，
 * 说明能往邻居家里灌水, 此时把二者高度差作为当前接水量累加到结果中，并将邻居灌满水，即更新
 * 为 lowest，然后将邻居入队并标记已访问。
 */
class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int n = heightMap.size();
    int m = heightMap[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));

    // 小顶堆，<weight, i*m+j> 二维下下标转一维
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    // 将四条边界入队
    for (int j = 0; j < m; j++) {
      heap.push({heightMap[0][j], j});
      heap.push({heightMap[n - 1][j], (n - 1) * m + j});
      visited[0][j] = visited[n - 1][j] = true;
    }
    for (int i = 1; i < n - 1; i++) {
      heap.push({heightMap[i][0], i * m});
      heap.push({heightMap[i][m - 1], i * m + m - 1});
      visited[i][0] = visited[i][m - 1] = true;
    }

    int mx[] = {0, 1, 0, -1};
    int my[] = {1, 0, -1, 0};
    int res = 0;
    // 从最外层一圈开始向内进行BFS搜索能灌水的格子
    while (!heap.empty()) {
      auto lowest = heap.top(); // 取出堆顶当前最小值
      heap.pop();

      int x = lowest.second / m;
      int y = lowest.second % m;
      for (int i = 0; i < 4; i++) { // 看一下四个邻居的格子，能不能往里灌水
        int nx = x + mx[i];
        int ny = y + my[i];
        // 跳过不合法的和已经遍历过的
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

        // 如果邻居格子比当前的格子矮，说明能往邻居家里灌水
        if (heightMap[nx][ny] < lowest.first) {
          res += lowest.first - heightMap[nx][ny];
          heightMap[nx][ny] = lowest.first; // 往邻居家里灌水
        }
        visited[nx][ny] = true; //标记已访问
        heap.push({heightMap[nx][ny], nx * m + ny}); // 邻居入队
      }
    }
    return res;
  }
};