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
