/**
 * https://leetcode-cn.com/problems/course-schedule-ii/
 * https://leetcode-cn.com/problems/course-schedule-ii/solution/ke-cheng-biao-ii-by-leetcode-solution/
 * 方法一：逆向思维，DFS + 栈
 */
class Solution {
 public:
  vector<int> res; // 拓扑排序栈
  vector<int> state;  // 0 unused, 1 searching, 2 done
  vector<vector<int>> linkTable; // 临接表

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    state.resize(numCourses);
    linkTable.resize(numCourses);
    // 构建临接表
    for (int i = 0; i < prerequisites.size(); i++)
      linkTable[prerequisites[i][1]].push_back(prerequisites[i][0]);
    // 从每个未使用的节点出发，进行拓扑排序
    for (int i = 0; i < linkTable.size(); i++) {
      if (!state[i]) {
        if (!dfs(i)) return {};
      }
    }
    // 拓扑排序次序是栈顶到栈低
    reverse(res.begin(), res.end());
    return res;
  }

  bool dfs(int node) {
    state[node] = 1; // 当前节点正在搜索
    // 遍历所有相邻的节点
    for (auto child : linkTable[node]) {
      if (state[child] == 0) { // unused，继续搜索下一级
        if (!dfs(child)) return false;
      } else if (state[child] == 1) { // searching，有环，拓扑排序失败
        return false;
      } else { // done，已入栈了，跳过
        continue;
      }
    }
    // 所有相邻节点都入栈了，回溯到上一层
    // node 的所有相邻节点可排序，则 node 可排序
    res.push_back(node);
    state[node] = 2;
    return true;
  }
};

/**
 * 方法二：正向思维，bfs+队列
 * 依次遍历所有入度为 0 的节点
 */
class Solution1 {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    vector<int> inEdge(numCourses);             // 每个节点的入度
    vector<vector<int>> linkTable(numCourses);  // 临接表
    for (const auto& next_pre : prerequisites) {
      inEdge[next_pre[0]]++;
      linkTable[next_pre[1]].push_back(next_pre[0]);
    }

    queue<int> q; // bfs 队列
    // 将所有入度为 0 的节点加入到队列
    for (int i = 0; i < numCourses; i++) {
      if (!inEdge[i]) q.push(i);
    }

    // 依次遍历所有入度为 0 的节点
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      res.push_back(node);
      // 遍历所有相邻的节点
      for (int child : linkTable[node]) {
        // 减小相邻节点的入度，减为 0 的入队
        if (--inEdge[child] == 0) q.push(child);
      }
    }
    // 若 res 没有包含所有节点，则拓扑排序失败
    if(res.size() != numCourses)
      return {};

    return res;
  }
};