/**
 * https://leetcode.cn/problems/design-hashmap/
 * 拉链法解决冲突
 */
class MyHashMap {
  int size;
  vector<list<pair<int, int>>> cache;

 public:
  MyHashMap() {
    size = 10000;
    cache.resize(size);
  }

  void put(int key, int value) {
    auto& l = cache[key % size];
    auto it = find_if(l.begin(), l.end(),
                      [key](pair<int, int>& n) { return n.first == key; });
    if (it == l.end()) {
      l.insert(l.end(), {key, value});
    } else {
      it->second = value;
    }
  }

  int get(int key) {
    auto& l = cache[key % size];
    auto it = find_if(l.begin(), l.end(),
                      [key](pair<int, int>& n) { return n.first == key; });
    if (it == l.end()) {
      return -1;
    } else {
      return it->second;
    }
  }

  void remove(int key) {
    auto& l = cache[key % size];
    l.remove_if([key](pair<int, int>& n) { return key == n.first; });
  }
};
