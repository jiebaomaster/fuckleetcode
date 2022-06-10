/**
 * https://leetcode-cn.com/problems/open-the-lock/
 * https://labuladong.gitee.io/algo/4/29/110/
 * 
 * 不管所有的限制条件，如何设计一个算法穷举所有可能的密码组合？
 * 如果只转一下锁，有几种可能？总共有 4 个位置，每个位置可以向上转，也可以向下转，
 * 也就是有 8 种可能。比如说从 "0000" 开始，转一次，可以穷举出 "1000", "9000", 
 * "0100", "0900"... 共 8 种密码。然后，再以这 8 种密码作为基础，对每个密码再
 * 转一下，穷举出所有可能…
 * 这就可以抽象成一幅图，每个节点有 8 种旋转方法，即有 8 个相邻的节点，旋转一次就是
 * 一个单位距离，即求 “0000” 节点到 target 节点的最短距离，这是典型的 BFS 
 */
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    // 记录数字是否已经入过队。死亡数字相当于已经入过队
    unordered_set<string> inq(deadends.begin(), deadends.end());
    
    // 死亡数字中有“0000”时一开始就不能转动
    if (inq.find("0000") != inq.end()) return -1;
    inq.insert("0000");
    queue<string> q; // 保存待遍历节点
    q.push("0000");

    int step = 0;

    while (!q.empty()) {
      /* 遍历当前队列中的所有节点，即一层 */
      for (int i = q.size(); i > 0; i--) {
        string cur = q.front();
        q.pop();

        /* 判断是否到达终点 */
        if (cur == target) return step;

        /* 将一个节点的未遍历相邻节点加入队列 */
        // 对于一个4位的数字，转动一次，可以取任意一位进行加减一共8总
        for (int j = 0; j < 4; j++) { // 每一位
          up(cur, j); // +1
          if (inq.find(cur) == inq.end()) {
            q.push(cur); // 入队
            inq.insert(cur);
          }

          down(cur, j); // 恢复
          down(cur, j); // -1
          if (inq.find(cur) == inq.end()) {
            q.push(cur);
            inq.insert(cur);
          }
          up(cur, j); // 恢复
        }
      }
      /* 在这里增加步数 */
      step++;
    }
    // 如果穷举完都没找到目标密码，那就是找不到了
    return -1;
  }
  // s[index]++
  void up(string& s, int index) {
    if (s[index] == '9')
      s[index] = '0';
    else
      s[index]++;
  }
  // s[index]--
  void down(string& s, int index) {
    if (s[index] == '0')
      s[index] = '9';
    else
      s[index]--;
  }
};