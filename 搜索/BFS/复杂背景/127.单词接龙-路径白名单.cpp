/**
 * https://leetcode.cn/problems/word-ladder/
 * 将 beginWord 转换成 endWord
 * 每次改变 word 中的一个字母，且经过的路径要在 wordList 中
 */
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int> visited; // 路径白名单，是否已经被使用过
    visited[beginWord] = 1;
    for (auto& s : wordList) {
      visited[s] = 0;
    }

    queue<string> q;
    q.push(beginWord);
    int depth = 0;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();
        if (n == endWord) return depth + 1;

        // 遍历下一个 n 的所有情况，n 的每一位都可以变成任意的字母
        for (int j = 0; j < n.size(); j++) {
          char pre = n[j];
          for (char c = 'a'; c <= 'z'; c++) {
            n[j] = c;
            // 下一跳 n 应该在路径白名单上，而且 还没有被使用过
            if (visited.find(n) != visited.end() && !visited[n]) {
              visited[n]++;
              q.push(n);
            }
          }
          n[j] = pre; // 恢复 n
        }
      }
      depth++;
    }
    return 0;
  }
};