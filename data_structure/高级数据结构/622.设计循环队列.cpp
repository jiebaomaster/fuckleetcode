/**
 * https://leetcode.cn/problems/design-circular-queue/
 * 方法一：[head, tail) 双指针
 */
class MyCircularQueue {
  int *cache, *cache_end;  // 堆上空间 [cache, cache_end)
  int *head,               // 队首位置
      *tail;               // 第一个可写位置，即队尾的后一个
  // 向后移动指针
  void next(int *&p) {
    p++;
    if (p == cache_end) p = cache;
  }

 public:
  MyCircularQueue(int k) {
    cache = new int[k];
    cache_end = cache + k;
    head = nullptr;
    tail = cache;
  }

  bool enQueue(int value) {
    if (isFull()) return false;

    *tail = value;
    if (isEmpty()) head = tail;
    next(tail);
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    next(head);
    if (head == tail) head = nullptr;
    return true;
  }

  int Front() { return isEmpty() ? -1 : *head; }

  int Rear() {
    if (isEmpty()) return -1;

    if (tail == cache)
      return *(cache_end - 1);
    else
      return *(tail - 1);
  }

  bool isEmpty() { return head == nullptr; }

  bool isFull() { return head == tail; }
};

/**
 * 方法二：head + size
 */
class MyCircularQueue {
  int *cache;
  int head;  // 当前队首
  int size;
  int capacity;

 public:
  MyCircularQueue(int k) : capacity(k), size(0) {
    cache = new int[k];
    head = 0;
  }

  bool enQueue(int value) {
    if (isFull()) return false;

    cache[(head + size) % capacity] = value;
    size++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    head = (head + 1) % capacity;
    size--;
    return true;
  }

  int Front() { return isEmpty() ? -1 : cache[head]; }

  int Rear() {
    if (isEmpty()) return -1;
    int tail = (head + size - 1) % capacity;
    return cache[tail];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }
};

/**
 * https://leetcode.cn/problems/design-circular-queue/solution/she-ji-xun-huan-dui-lie-by-leetcode-solu-1w0a/
 * 方法三：k+1长度数组，哨兵
 * 尾元素的下一个元素作为哨兵，不存储元素，用来区分空和满
 * 当循环队列中只有一个哨兵元素时，队列为空，此时 head==tail
 * 当循环队列中只剩下一个空存储单元时，队列已满，此时 (tail + 1) % capacity == head
 */
class MyCircularQueue {
  int capacity;
  vector<int> cache;
  int tail; // 哨兵位置，即尾元素的下一个位置，用来区分
  int head; // 第一个元素的位置

 public:
  MyCircularQueue(int k) {
    head = tail = 0;
    capacity = k + 1;
    cache.resize(k + 1);
  }

  bool enQueue(int value) {
    if (isFull()) return false;
    cache[tail++] = value;
    tail %= capacity;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    head++;
    head %= capacity;
    return true;
  }

  int Front() { return isEmpty() ? -1 : cache[head]; }

  int Rear() {
    return isEmpty() ? -1 : cache[(tail - 1 + capacity) % capacity];
  }

  bool isEmpty() { return head == tail; }

  bool isFull() { return (tail + 1) % capacity == head; }
};