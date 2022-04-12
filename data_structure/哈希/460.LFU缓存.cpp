/**
 * https://leetcode-cn.com/problems/lfu-cache/
 * 双hash法
 * key->node 查找元素是否存在
 * freq->list 查找各频率的元素
 * 删除和移动时，可由 node 直接找到 list 中的节点
 * lfu 中 node 的频率必定是单调增的
 */
class Node {
 public:
  int key;
  int val;
  int freq;
  Node* prev;
  Node* next;

  Node(int key, int val) : key(key), val(val), freq(1) {
    prev = nullptr;
    next = nullptr;
  }
};

class DoubleList {
 public:
  int size;
  Node* head;
  Node* tail;
  DoubleList() : size(0) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }
  void remove(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    size--;
  }
  void push_back(Node* n) {
    n->next = tail;
    n->prev = tail->prev;
    tail->prev->next = n;
    tail->prev = n;
    size++;
  }
};

class LFUCache {
  int capacity;
  int size;
  unordered_map<int, Node*> key_node;
  unordered_map<int, DoubleList*> freq_list;
  int min_freq; // cache 中最小频率，用于删除
  // 将一个 node 从一个 list 移动到另一个 list
  void update_freq(Node* n) {
    freq_list[n->freq]->remove(n);
    if (freq_list.find(n->freq + 1) == freq_list.end()) {
      freq_list.insert({n->freq + 1, new DoubleList()});
    }
    freq_list[n->freq + 1]->push_back(n);
    // 移动 node 有可能造成最低频率改变
    if (n->freq == min_freq && freq_list[min_freq]->size == 0) min_freq++;
    n->freq++;
  }

 public:
  LFUCache(int capacity) : capacity(capacity), min_freq(1), size(0) {
    freq_list.insert({1, new DoubleList()});
  }

  int get(int key) {
    auto n = key_node.find(key);
    if (n == key_node.end()) return -1;
    update_freq(n->second);
    return n->second->val;
  }

  void put(int key, int value) {
    if (capacity == 0)  // 容量为0代表不存储
      return;
    auto n = key_node.find(key);
    if (n != key_node.end()) {  // key 存在，更新
      update_freq(n->second);
      n->second->val = value;
      return;
    }

    // 达到容量限制，先将最小freq队列的最先添加的元素删除
    if (capacity == size) {  // remove current min_freq node
      auto removeNode = freq_list[min_freq]->head->next;
      // form key->node
      key_node.erase(removeNode->key);
      // from freq list
      freq_list[min_freq]->remove(removeNode);
      delete removeNode;
      size--;
    }
    // 创建新的 node
    auto newNode = new Node(key, value);
    key_node[key] = newNode;
    freq_list[1]->push_back(newNode);
    min_freq = 1;
    size++;
  }
};

/**
 * 方法二：利用 STL list 容器，
 * 关键是 key->node 中 node 保存 node 在 list 中的迭代器
 * 这样就可在删除和移动时，由 node 直接找到 list 中的节点
 */
class Node {
 public:
  int key;
  int val;
  int freq;
  Node* prev;
  Node* next;

  Node(int key, int val, int freq) : key(key), val(val), freq(freq) {
    prev = nullptr;
    next = nullptr;
  }
};

class LFUCache {
  int capacity;
  int size;
  unordered_map<int, list<Node>::iterator> key_node;
  unordered_map<int, list<Node>> freq_list;
  int min_freq;
  void update_freq(list<Node>::iterator n) {
    int key = (*n).key;
    int val = (*n).val;
    int freq = (*n).freq;
    freq_list[freq].erase(n);
    // 头插尾删
    freq_list[freq + 1].push_front(Node(key, val, freq + 1));
    // 移动node 有可能造成最低频率改变
    if (freq == min_freq && freq_list[min_freq].size() == 0) 
      min_freq++;
    key_node[key] = freq_list[freq + 1].begin(); // 更新迭代器
  }

 public:
  LFUCache(int capacity) : capacity(capacity), min_freq(1), size(0) {}

  int get(int key) {
    auto n = key_node.find(key);
    if (n == key_node.end()) return -1;
    update_freq(n->second);
    return n->second->val;
  }

  void put(int key, int value) {
    if (capacity == 0) return;
    auto n = key_node.find(key);
    if (n != key_node.end()) {
      update_freq(n->second);
      n->second->val = value;
      return;
    }

    if (capacity == size) {  // remove current min_freq node
      auto removeNode = freq_list[min_freq].back();
      // form key->node
      key_node.erase(removeNode.key);
      // from freq list
      freq_list[min_freq].pop_back();
      size--;
    }
    freq_list[1].push_front(Node(key, value, 1));
    key_node[key] = freq_list[1].begin();
    min_freq = 1;
    size++;
  }
};