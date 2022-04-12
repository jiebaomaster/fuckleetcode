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
    void insert(Node* n) {
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
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */