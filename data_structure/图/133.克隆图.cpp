/**
 * https://leetcode.cn/problems/clone-graph/
 * 图的深度拷贝
 */
class Solution {
 public:
  // 源节点 -> 副本
  unordered_map<Node*, Node*> old_new;
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    // 拷贝本事
    auto newNode = new Node(node->val);
    old_new[node] = newNode;
    // 拷贝临接表
    for (auto n : node->neighbors) {
      if (old_new[n]) { // 已拷贝的，直接加入
        newNode->neighbors.push_back(old_new[n]);
      } else { // 否则，dfs 拷贝邻接节点
        newNode->neighbors.push_back(cloneGraph(n));
      }
    }
    return newNode;
  }
};