/**
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 * 
 */
class Trie {
  struct Node {
    char val; // 本节点的字符
    int time = 0; // 本节点表示单词出现的次数
    Node* next[26]; // 下一个字符，英文有26个字符，所以有26叉
    explicit Node(char c) : val(c) {
      for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
  };

 public:
  Node* root; // 根节点，不包含前缀
  Trie() { root = new Node(0); }

  void insert(string word) {
    auto p = root;
    for (char c : word) {
      if (!p->next[c - 'a']) { // 建立不存在的前缀节点
        p->next[c - 'a'] = new Node(c);
      }
      p = p->next[c - 'a'];
    }
    p->time++; // 
  }

  bool search(string word) {
    auto p = root;
    for (char c : word) {
      if (!p->next[c - 'a']) {
        return false;
      }
      p = p->next[c - 'a'];
    }
    return p->time;
  }

  bool startsWith(string prefix) {
    auto p = root;
    for (char c : prefix) {
      if (!p->next[c - 'a']) {
        return false;
      }
      p = p->next[c - 'a'];
    }
    return true;
  }
};