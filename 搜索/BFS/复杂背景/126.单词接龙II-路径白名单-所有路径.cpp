/**
 * https://leetcode.cn/problems/word-ladder-ii/
 * 与 127 题相似，但要求输出所有路径
 * 
 * 1. 队列中保存路径，才能在最后输出路径
 * 2. 在一层遍历完后才进行节点占用，即允许在同一层使用相同的节点
 *    ["red","ted","tex","tax"]
 *    ["red","rex","tex","tax"]
 *    第三层 tex 在两条可选路径中使用到
 */
class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    vector<vector<string>> res;

    unordered_map<string, int> visited;
    for (auto& s : wordList) {
      visited[s] = 0;
    }
    visited[beginWord] = 1;

    // 队列中保存的是路径，这样才能输出所有路径
    queue<vector<string>> q;
    q.push({beginWord});
    bool got = false;
    while (!q.empty()) {
      unordered_set<string> levelVisited;
      for (int i = q.size(); i > 0; i--) {
        auto path = q.front();
        q.pop();
        auto s = path.back();
        if (s == endWord) {
          got = true;
          res.push_back(path); // 输出路径
          continue;
        }

        for (int j = 0; j < s.size(); j++) {
          char pre = s[j];
          for (char c = 'a'; c <= 'z'; c++) {
            s[j] = c;
            if (visited.find(s) != visited.end() && (!visited[s])) {
              levelVisited.insert(s);
              path.push_back(s);
              q.push(path);
              path.pop_back();
            }
          }
          s[j] = pre;
        }
      }
      if (got) break;
      // 在一层遍历完后才进行占用，即允许在同一层使用相同的节点
      for (auto s : levelVisited) {
        visited[s]++;
      }
    }
    return res;
  }
};