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
