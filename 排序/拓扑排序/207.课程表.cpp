/**
 * https://leetcode-cn.com/problems/course-schedule/
 * 本题和第 210 题一样，只是本题只需要做判断，不需要保存最终排序结果
 *
 * 方法一：dfs
 */
class Solution {
 public:
  vector<vector<int>> linkTable;
  vector<int> state;
  bool valid = true;
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    linkTable.resize(numCourses);
    state.resize(numCourses);
    for (const auto& next_pre : prerequisites)
      linkTable[next_pre[1]].push_back(next_pre[0]);

    for (int i = 0; i < numCourses && valid; i++) {
      if (!state[i]) {
        dfs(i);
      }
    }
    return valid;
  }
  void dfs(int node) {
    state[node] = 1;
    for (auto child : linkTable[node]) {
      if (state[child] == 0) {
        dfs(child);
        if (!valid) return;
      } else if (state[child] == 1) {
        valid = false;
        return;
      } else {
        continue;
      }
    }
    state[node] = 2;
  }
};

/**
 * 方法二：bfs
 */
class Solution1 {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inEdge(numCourses);
    vector<vector<int>> linkTable(numCourses);

    for (const auto& next_pre : prerequisites) {
      linkTable[next_pre[1]].push_back(next_pre[0]);
      inEdge[next_pre[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
      if (!inEdge[i]) q.push(i);

    int cnt = 0;
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      cnt++;
      for (int child : linkTable[n])
        if (--inEdge[child] == 0) q.push(child);
    }

    return cnt == numCourses;
  }
};