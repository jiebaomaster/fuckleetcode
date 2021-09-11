# leetcode 刷题笔记

## 数据结构

### 单调栈

单调栈用途不太广泛，只处理一种典型的问题，叫做 Next Greater Element

[单调栈结构解决三道算法题](https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dan-tiao-zhan)
[补充例题](https://github.com/jiebaomaster/kaoyan/blob/master/data_structure/monotonyStack.cpp)

### 二分法

二分法通常以应用题的形式出现，求某个限定条件 t 下的最值，且限定条件和所求值之间存在单调函数关系。通常将所求值 x 当做自变量，限定条件作为因变量，建立函数关系 f(x)，根据 f(x) 与 t 的关系进行二分查找，寻找最值。其中，要查找的 x 的范围通常不会直接给出，需要根据题目条件获取，通常和题目直接给出的数组有关（元素的最值，所有元素的和等）。

### 双指针法

**快慢指针** 如果要操作的节点有明确的位置关系，可以考虑快慢指针，如快指针先走 n 步，快指针一次走 2 步。
**左右指针** 如果列表有序，可以考虑左右指针。
**滑动窗口** 左右指针的一种应用，通常用于在 O(n) 时间内求字符串子串相关问题。

``` c++
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
  unordered_map<char, int> need,  // 可选，目标子串 t 的元素出现的次数
                          window; // 窗口内元素出现的次数
  for (char c : t) need[c]++;     // 用目标字符串初始化 need

  int left = 0, right = 0;
  int valid = 0; // 可选，记录窗口中有几个元素满足要求了
  while (right < s.size()) {
    // c 是将移入窗口的字符，右移窗口
    char c = s[right++];
    // 进行窗口内数据的一系列更新
    ...

    // 判断左侧窗口是否要收缩，滑动窗口需要保持题目要求的某种状态
    while (window needs shrink) {
      // d 是将移出窗口的字符，左移窗口
      char d = s[left++];
      // 进行窗口内数据的一系列更新
      ...
    }
  }
}
```
