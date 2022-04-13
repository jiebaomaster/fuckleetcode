/**
 * https://leetcode-cn.com/problems/lru-cache/
 * hash表快速查找缓存
 * 双向链表实现lru的缓存，头插尾出法，操作节点后更新节点在链表中的位置
 * 
 * 方法一：手写双向链表
 */
class LRUCache {
 public:
  struct Node {
    Node* prev;
    Node* next;
    int val;
    int key;
    Node(int key, int val) : prev(nullptr), next(nullptr), key(key), val(val) {}
  };

  class DoubleList {
    int len;
    // 头尾辅助节点，在插入和删除时就不用考虑边界条件了
    Node* head;
    Node* tail;

   public:
    DoubleList() : len(0) {
      head = new Node(-1, -1);
      tail = new Node(-1, -1);
      head->next = tail;
      tail->prev = head;
    }
    int size() { return len; }
    void remove(Node* n) {
      n->prev->next = n->next;
      n->next->prev = n->prev;
      len--;
    }
    Node* removeTail() {
      auto n = tail->prev;
      remove(n);
      return n;
    }
    void insert(Node* n) { // 头插
      n->next = head->next;
      n->prev = head;
      head->next->prev = n;
      head->next = n;
      len++;
    }
  };

  int capacity;
  DoubleList* cache; // 缓存链表
  unordered_map<int, Node*> has; // 加速 key 查找
  LRUCache(int capacity) : capacity(capacity), cache(new DoubleList()) {}

  int get(int key) {
    auto n = has.find(key);
    if (n == has.end()) return -1;

    cache->remove(n->second);
    cache->insert(n->second);

    return n->second->val;
  }

  void put(int key, int value) {
    auto n = has.find(key);
    if (n == has.end()) {
      if (cache->size() == capacity) {
        auto tail = cache->removeTail();
        has.erase(tail->key);
        delete tail;
      }
      auto nn = new Node(key, value);
      cache->insert(nn);
      has[key] = nn;
    } else {
      n->second->val = value;
      cache->remove(n->second);
      cache->insert(n->second);
    }
  }
};

/**
 * 方法二：STL list
 */
class LRUCache {
  class Node {
   public:
    int key;
    int val;
    Node(int key, int val) : key(key), val(val) {}
  };

  int capacity;

  list<Node> cache;
  unordered_map<int, list<Node>::iterator> key_node;

  // 更新链表节点
  void update(list<Node>::iterator node) {
    int key = node->key;
    int val = node->val;
    cache.erase(node);
    cache.push_front(Node(key, val));
    key_node[key] = cache.begin();
  }

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto it = key_node.find(key);
    if (it == key_node.end()) return -1;

    update(it->second);
    return it->second->val;
  }

  void put(int key, int value) {
    auto it = key_node.find(key);
    if (it != key_node.end()) {
      it->second->val = value;
      update(it->second);
      return;
    }

    if (cache.size() == capacity) {
      auto removeNode = cache.back();
      key_node.erase(removeNode.key);
      cache.pop_back();
    }

    cache.push_front(Node(key, value));
    key_node[key] = cache.begin();
  }
};