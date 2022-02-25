class Node {
 public:
  Node *next, *prev;
  int key, val;

  Node(int key, int val) {
    this->key = key;
    this->val = val;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoubleList {
 public:
  Node *head, *tail;
  size_t size;
  DoubleList() {
    this->size = 0;
    this->head = new Node(0, 0);
    this->tail = new Node(0, 0);
    this->tail->prev = this->head;
    this->head->next = this->tail;
  }

  void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    this->size--;
  }
  void push_back(Node *node) {
    node->next = this->tail;
    node->prev = this->tail->prev;
    this->tail->prev->next = node;
    this->tail->prev = node;

    this->size++;
  }
};

class LRUCache {
 public:
  DoubleList *cache;
  unordered_map<int, Node *> *hashmap;
  int capacity;

  LRUCache(int capacity) {
    this->cache = new DoubleList();
    this->hashmap = new unordered_map<int, Node *>;
    this->capacity = capacity;
  }

  int get(int key) {
    auto it = this->hashmap->find(key);
    if (it == this->hashmap->end()) return -1;
    Node *node = it->second;
    this->cache->removeNode(node);
    this->cache->push_back(node);
    return node->val;
  }

  void put(int key, int val) {
    auto it = this->hashmap->find(key);
    if (it == this->hashmap->end()) {
      if (this->capacity == this->cache->size) {
        Node *tmp = this->cache->head->next;
        this->hashmap->erase(tmp->key);
        this->cache->removeNode(tmp);
        delete tmp;
      }
      Node *tmp = new Node(key, val);
      this->hashmap->insert(make_pair(key, tmp));
      this->cache->push_back(tmp);
    } else {
      Node *node = it->second;
      node->val = val;
      this->cache->removeNode(node);
      this->cache->push_back(node);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */