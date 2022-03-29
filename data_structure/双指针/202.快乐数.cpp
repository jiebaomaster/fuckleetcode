/**
 * https://leetcode-cn.com/problems/happy-number/
 * 方法一：保存所有求值路径上的 x'
 * 不断求 x 的下一次分割 x'，若这个数不是快乐数，则会求得重复的 x'，
 */
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> hash; // 保存所有求值路径上的 x'
    while (n != 1) {
      int tmp = 0;
      while (n) {
        tmp += (n % 10) * (n % 10);
        n /= 10;
      }
      // 有重复，则不是快乐数
      if (hash.count(tmp)) return false;
      hash.insert(tmp);
      n = tmp;
    }
    return true;
  }
};

/**
 * 方法二：快慢指针
 * 这题可以用快慢指针的思想去做，有点类似于检测是否为 141 判断链表里是否有环
 * 不断求 x 的下一次分割 x'，可以构成一个链表，
 *    若这个这个数是快乐数，则链表最后一个结点的值为 1，
 *    若这个数不是快乐数，则会求得重复的 x'，相当于链表中存在环 
 * 所以可以用快慢指针判断链表中是否有环，取 next 指针操作变为求下一个 x' 操作
 */
class Solution1 {
 public:
  bool isHappy(int n) {
    int fast = n;
    int slow = n;
    while (fast != 1) {
      slow = next(slow);
      fast = next(fast);
      fast = next(fast);
      if (fast == slow && fast != 1) // 相等说明出现环
        return false;
    }

    return true;
  }
  // 求 x 的下一个 x'
  int next(int n) {
    int tmp = 0;
    while (n) {
      tmp += (n % 10) * (n % 10);
      n /= 10;
    }
    return tmp;
  }
};