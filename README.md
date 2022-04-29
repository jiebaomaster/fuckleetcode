# leetcode 刷题笔记

## 数据结构

### 随机数

随机数问题以下基本类型：

- O(1) 时间从集合中取随机数，要排除黑名单中的数：方法是在逻辑上讲黑名单中的数都放到数组的后半部分去 [710.黑名单中的随机数](./data_structure/随机数/710.黑名单中的随机数.cpp)
- 大数据流中的随机抽样问题：当内存无法加载全部数据时，如何从包含未知大小的数据流中随机选取k个数据，并且要保证每个数据被抽取到的概率相等。
  - [蓄水池抽样算法](https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/)
  - 解法：假设数据流含有 N 个数，如果要保证所有的数被抽到的概率相等，那么每个数抽到的概率应该为 1/N。遍历所有数据，只记录选中的数，当遇到第 i 个数时，以 1/i 的概率保留它，(i-1)/i 的概率保留原来的数。
  - 例题：[382.链表随机节点-任意目标数](./trick/数学/随机/382.链表随机节点-任意目标数.cpp) [398.随机数索引-固定目标数](./trick/数学/随机/398.随机数索引-固定目标数.cpp)
- 随机洗牌：一个没有重复元素的数组数组 nums，设计算法来打乱。打乱后，数组的所有排列应该是 等可能 的。
  - 解法：对于下标 x 而言，从 [x, n - 1][x,n−1] 中随机出一个位置与 x 进行值交换，当所有位置都进行这样的处理后，我们便得到了一个公平的洗牌方案。
  - 例题：[384.打乱数组](./trick/数学/随机/384.打乱数组.cpp)

### 字符串

字符串处理：见到括号就用栈，见到计数就用哈希表，然后面向测试用例慢慢修bug

用栈解决字符串处理问题：
- 添加时可能向前删除的字符串 [71.简化路径](./data_structure/栈/71.简化路径.cpp)
- 展开局部重复的字符串，重复次数在前 [394.字符串解码](./data_structure/栈/394.字符串解码.cpp)
- 展开局部重复的字符串，重复次数在后 [726.原子的数量](./data_structure/栈/726.原子的数量.cpp)

### 链表

双指针可以解决链表中环的问题
- [141.判断链表是否有环](./data_structure/双指针/141.判断链表是否有环.cpp)
- [142.求链表中环的入口](./data_structure/双指针/142.求链表中环的入口.cpp)
- 链表的首位相接构成环[160.相交链表](./data_structure/链表/160.相交链表.cpp)
- 静态链表 [287.寻找重复数](./data_structure/数组&字符串/数组中元素出现的次数/287.寻找重复数.cpp)
- x->f(x)->f(f(x))... 连续求函数值产生链表[202.快乐数](./data_structure/双指针/202.快乐数.cpp)

## 搜索

DFS（回溯）可以遍历出所有可能的解，从而得到这些解中符合题目要求（通常是某种最值）的那个
BFS 问题的本质就是让你在一幅「图」中找到从起点 start 到终点 target 的最近距离，即终点是确定的，所求的是起点和终点的（最值）距离（单源最短路径，路径不能为负）。

需要转换成 BFS 的问题特征：通过对某一个初始状态做一系列操作，转化成目标状态，**求最少需要的操作次数**
抽象成图的问题：节点即每种可能的状态，边表示对处于每一种状态时所做的“选择”，当前状态通过做选择转移到另一种状态。
很多益智游戏都是这样，虽然看起来特别巧妙，但都架不住暴力穷举，常用的算法就是回溯算法或者 BFS 算法。只要穷举出所有可行的解，就能找到符合需求的解。

### BFS

``` cpp
// 计算从起点 start 到终点 target 的最近距离
int BFS(Node start, Node target) {
    queue<Node> q; // 保存待遍历节点
    unordered_set<Node> visited; // 避免走回头路
    
    q.push(start); // 将起点加入队列
    visited.insert(start);
    int step = 0; // 记录扩散的步数

    while (!q.empty()) {
        /* 每次 for 遍历一层节点 */
        for (int i = q.size(); i > 0; i--) {
            Node cur = q.front();
            q.pop();
            /* 划重点：这里判断是否到达终点 */
            if (cur == target)
                return step;
            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj()) {
                if (visited.find(x) == visited.end()) {
                    q.push(x);
                    visited.insert(x);
                }
            }
        }
        /* 划重点：更新步数在这里 */
        step++;
    }
    // 穷举完都没找到目标，目标不存在
    return -1;
}
```

### 二叉树

#### 遍历二叉树

[二叉树遍历方法大全（包含莫里斯遍历动图）](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-bian-li-fang-fa-da-quan-bao-han-mo-li-2/)

莫里斯遍历

莫里斯遍历不需要递归或者临时的栈空间就可以完成遍历，空间复杂度是常数。但是为了解决从子节点找到父节点的问题，需要临时修改树的结构，建立左子树中最右边节点到父节点的关系，在遍历完成之后复原成原来的树结构。
时间复杂度分析：虽然有嵌套的循环，但是对于任意根节点来说，只会进行两次搜索前驱节点加上对自身的遍历，综合来说，树的每个节点的遍历次数最多是 3 次。即 O(3n)

后序遍历的性质：后序遍历可以通过前序遍历得到，按“父右左”的顺序遍历，然后反转结果。相应地，可以通过修改前序遍历的代码得到后序遍历的代码：

1. 把原来的所有的 right 改成 left，原来的 left 改成 right
2. 最后添加一步结果反转

#### 二叉树中的路径

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中至多出现一次。该路径至少包含一个节点，且不一定经过根节点。
- 求路径上节点值相同的最大路径长度 [687.最长同值路径](./data_structure/树/树中的路径/687.最长同值路径.cpp)
- 求路径上节点和的最大值 [124.二叉树中的最大路径和](./data_structure/树/树中的路径/124.二叉树中的最大路径和.cpp)
- 求最长的路径长度 [543.二叉树的直径](./data_structure/树/树中的路径/543.二叉树的直径.cpp)
- 判断是否存在路径上节点和等于 target 的从根开始的路径 [112.路径总和](./data_structure/树/树中的路径/112.路径总和.cpp)
- 输出所有路径上节点和等于 target 的从根开始的路径 [113.路径总和II](./data_structure/树/树中的路径/113.路径总和II.cpp)
- 输出二叉树上到结点 target 的路径长度为 k 的结点个数 [](./data_structure/树/树中的路径/863.二叉树中所有距离为K的结点.cpp)

- 二维矩阵

## O(1) 操作

1. 如何删除链表中指针指定节点？将其值与下一个节点的值交换，删除下一个
2. 如何删除数组中索引指定元素？将其值与数组最后一个元素值交换，删除最后一个

### 单调栈

单调栈用途不太广泛，可以用来在一维数组中寻找每个元素的**下一个更大/小的元素** [739.每日温度](./data_structure/单调栈/739.每日温度.cpp)
其中一维数组可以是循环数组 [503.下一个更大元素-循环数组](。/../data_structure/单调栈/503.下一个更大元素-循环数组.cpp)
求数组中某个子序列的面积=子序列的长度*子序列的最小高度 [84.柱状图中最大的矩形](./data_structure/单调栈/84.柱状图中最大的矩形.cpp)，在栈顶元素 top 出栈时，入栈元素为 cur，则 top 就是子序列[top-1,cur]的最小值
单调栈的单调性还可以用来保证子串的最小字典序 [316.去除重复字母](./data_structure/单调栈/字典序最小子串/316.去除重复字母.cpp) [402.移掉K位数字](./data_structure/单调栈/字典序最小子串/402.移掉K位数字.cpp)

### 二分法

二分法通常以应用题的形式出现，求某个限定条件 t 下的最值，且限定条件和所求值之间存在单调函数关系。通常将所求值 x 当做自变量，限定条件作为因变量，建立函数关系 f(x)，根据 f(x) 与 t 的关系进行二分查找，寻找最值。其中，要查找的 x 的范围通常不会直接给出，需要根据题目条件获取，通常和题目直接给出的数组有关（元素的最值，所有元素的和等）。

### 双指针法

**快慢指针** 如果要操作的节点有明确的位置关系（中位数，倒数第 n 个），可以考虑快慢指针，如快指针先走 n 步，快指针一次走 2 步。快慢指针也用于列表中一次遍历原地去重，删除目标元素。
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

## 动态规划

### DP 定义

一维
二维

题目要求“不超过 K”条件，可以转化为一维条件“恰好 = k”，最后需要额外遍历一次“恰好条件”(1~K)求最值 [787.K站中转内最便宜的航班](./dp/复杂背景/787.K站中转内最便宜的航班.cpp)

dp的顺序，一般从起点出发，一直dp求解到终点；如果dp附加有额外的状态，可以考虑从终点出发，dp求解到起点 [174.地下城游戏](./dp/复杂背景/174.地下城游戏.cpp) [514.自由之路](./dp/复杂背景/514.自由之路.cpp)

二维 DP 可以从一维数组中产生，这被称为区间 DP，为求一维数组 arr 中的某个最值，可以从其子串中递推。通常定义 dp[i][j] 表示对于 arr 的子串 arr[i..j] 的所求最值 [516.最长回文子序列](./dp/子序列问题/516.最长回文子序列.cpp) [1312.让字符串成为回文串的最少插入次数](./dp/1312.让字符串成为回文串的最少插入次数.cpp) [877.石子游戏](./dp/复杂背景/877.石子游戏.cpp)

三维
[股票买卖问题的一般情况](./dp/复杂背景/股票买卖的最佳时机/188.交易k次.cpp)
[877.石子游戏](./dp/复杂背景/877.石子游戏.cpp)

### DP 顺序

**关于「状态」的穷举，最重要的一点就是：状态转移所依赖的状态必须被提前计算出来。**

可以根据 base case 和最终状态进行推导。
例：一个二维的 dp 问题，如果已知 dp[i][i]，dp[i][j] 依赖 dp[i][k] 和 dp[k][j]，其中 `i<k<j`，要求 dp[0][n]，显然应该先按行从下往上，再按列从左往右的方法，这样在计算 dp[i][j] 时，每个 dp[i][k] 和 dp[k][j] 都已经被计算出来了。 [312.戳气球](./dp/复杂背景/312.戳气球.cpp)

``` text
 j
------------>
             ^
* . . . . #  |
. * . . . .  |
. . * - - ?  |
. . . * . |  | i
. . . . * |  |
. . . . . *  |
```

只要涉及求最值，没有任何奇技淫巧，一定是穷举所有可能的结果，然后对比得出最值

### 在复杂数据结构中 DP

图 [787.K站中转内最便宜的航班](./dp/复杂背景/787.K站中转内最便宜的航班.cpp)
二叉树 [337.打家劫舍-二叉树](dp/复杂背景/打家劫舍/337.打家劫舍-二叉树.cpp)

### 子序列问题

- 两个字符串 dp[i][j]，表示以 s1[i] 和 s2[j] 结尾的...
- 一个字符串通常 dp[i]，表示以 s[i] 结尾的...
  - 如果涉及到两个字符的位置如回文，可以设 dp[i][j], 表示子串s[i...j]的...

### 背包问题

[用一种规律搞定背包问题](https://leetcode-cn.com/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/)

背包问题具备的特征：给定一个 target，target 可以是数字也可以是字符串，再给定一个数组 nums，nums 中装的可能是数字，也可能是字符串，问：能否使用 nums 中的元素做各种排列组合得到target。

对于一个背包问题：

1. 分析是哪种背包问题：
   1. 组合问题：“恰好”装满为 j 的背包，有几种方法
   2. 判断问题：能否“恰好”装满容量为 j 的背包
   3. 最值问题：容量为 j 的背包，最多“可以”装多少，最少使用几个物品
2. 01背包 还是 完全背包，即 nums 数组中的元素是否可以重复使用。
3. 如果是组合问题，是否需要考虑元素之间的顺序，解法不同

#### 结果集中元素的顺序

在组合问题中

- 一般的组合问题，不考虑结果中元素的顺序，即求组合数
  - 一般的思路是先遍历 num[]，分类讨论是否选中 num[i]，如果把第 i 个物品装入背包，那么恰好装满背包的方法数，取决于使用前面 i 个物品（完全背包）装满容量为 j-num[i] 的背包的方法数，即 dp[i][j-coins[i]]。
- 如果要考虑结果中元素的顺序，{1,2} 和 {2,1} 作为两个结果，即求排列数 [377.组合总和Ⅳ-完全-排列数](./dp/背包问题/组合问题/377.组合总和Ⅳ-完全-排列数.cpp)
  - 考虑把第 i 个物品装入背包时 dp[i][j] 不再等于 dp[i][j-num[i]]，因为新加入的 num[i] 可以插入 dp[i][j-coins[i]] 的结果集的不同位置中产生更多的排列
  - 例如，考虑 num[]={1,2,3}，target=5，易知 dp[3][2] 的结果集为 {1,1} {2}，共 2 个，求 dp[3][5]，当选中 num[2]=3 时，结果集除了对应 dp[3][2] 的 {1,1,3} {2,3} 还有 {3,1,1} {1,3,1} {3,2} 共 5 个

排列和组合主要影响的是遍历的次序

- 组合数问题，外层循环遍历备选数 nums，内层循环遍历背包容量 target。采用经典的二维 dp 定义即可。
- 排列数问题，外层循环遍历背包容量 target，内层循环遍历备选数 nums。定义 dp[i] 表示和为 i 的排列个数，则 `dp[i] = ∑dp[i-nums[k]], 0<=k<nums.size()`

背包问题的最值问题，求最少使用几个物品时，不必考虑结果集中元素的顺序，采用组合数或者排列数的写法都可以

## 回溯

回溯算法经典框架，考虑结果中每一个位置上的选择，递归层级表示了当前考虑的位置。

``` javascript
result = [] // 结果集
function backtrack(路径, 选择列表){
   if (满足结束条件)
      result.add(路径)
      return

   for(选择 in 选择列表) // 遍历位置 i 的所有选择
      做选择
      backtrack(路径, 选择列表) // 考虑位置 i+1 的选择
      撤销选择
}
```

[C++ 总结了回溯问题类型 带你搞懂回溯算法(大量例题)](https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/)

回溯算法能解决排列组合问题。子集问题是组合问题的特例，求子集相对于求所有选中个数的组合。

|类型|题目|关键点|
|---|---|---|
|子集|[90.子集II-备选数重复](./回溯/子集/90.子集II-备选数重复.cpp)<br>[78.子集-备选数唯一](./回溯/子集/78.子集-备选数唯一.cpp)<br>[784.字母大小写全排列](./回溯/子集/784.字母大小写全排列.cpp)|子集和组合的求解方法相同，只是子集要记录所有组合|
|组合|[39.组合总和-备选数唯一-重复选择](./回溯/组合/39.组合总和-备选数唯一-重复选择.cpp)<br>[40.组合总和II-备选数重复-一次选择](./回溯/组合/40.组合总和II-备选数重复-一次选择.cpp)<br>[216.组合总和III-备选数唯一-一次选择-选k个](./回溯/组合/216.组合总和III-备选数唯一-一次选择-选k个.cpp)<br>[77.组合-n个数里挑k个](./回溯/组合/77.组合-n个数里挑k个.cpp)|子集、组合类问题，关键是用一个 index 参数来控制选择列表，防止元素重复被选|
|排列|[46.全排列-备选数唯一](./回溯/排列/46.全排列-备选数唯一.cpp)<br>[47.全排列-备选数重复](./回溯/排列/47.全排列-备选数重复.cpp)<br>[剑指offer38.字符串的排列](./回溯/排列/剑指offer38.字符串的排列.cpp)|排列类问题使用 used 数组来标识元素是否已被选择，防止元素重复被选|
|搜索|[22.括号生成](./回溯/线性搜索/22.括号生成.cpp)<br>[131.分割回文串](./回溯/线性搜索/131.分割回文串.cpp)<br>[401.二进制手表](./回溯/线性搜索/401.二进制手表.cpp)<br>[698.划分为k个相等的子集](./回溯/线性搜索/698.划分为k个相等的子集.cpp)|遍历所有的可能性，判断每一种情况是否符合题意|
|矩阵搜索|[37.解数独](./回溯/矩阵搜索/37.解数独.cpp)<br>[51.N皇后](./回溯/矩阵搜索/51.N皇后.cpp)<br>[79.单词搜索](./回溯/矩阵搜索/79.单词搜索.cpp)|对于矩阵中的每一个点，需要根据题意确定递归的方向，通常有“上下左右”四个方向|

子集、组合与排列是不同性质的概念。子集、组合是无关顺序的，而排列是和元素顺序有关的，如 [1，2] 和 [2，1] 是同一个组合(子集)，但 [1,2] 和 [2,1] 是两种不一样的排列！！！！因此被分为两类问题

回溯和动态规划本质上都是搜索，动态规划通过重复子问题加快了搜索速度。回溯能记录下所有选择的路径，动态规划不能记录所有路径，但是能用来求选择的数量、判断能否成功、求所有选择中的某个最值。
通常只有在需要列举出所有解决方案的时候使用回溯，其他情况下使用 DP，如背包问题中的组合问题用 DP 解决，详见上文“动态规划-背包问题”章节。

### DFS

DFS 可以解决一类常见的问题：**给定一个序列（元素唯一），枚举这个序列的所有子序列（子集）**
基本思想是：依次考虑序列中的每一个元素 nums[i]，可以选择 nums[i]，也可以不选择，记录在 track 中。枚举所有子序列，即可求得符合题目要求的“最优子序列”。显然，这个问题也等价于**枚举从 N 个数中选择 K 个数的所有方案**。
[78.子集-元素唯一](./回溯/子集/78.子集-元素唯一.cpp) [77.组合-n个数里挑k个](./回溯/组合/77.组合-n个数里挑k个.cpp)

DFS 的经典框架，考虑备选集中的每一个元素是否被选中

``` javascript
result = [] // 结果集
cur = 0; // 选择 nums[i] 产生的影响
function dfs(路径, i, nums) { // 考虑 nums[i] 的选择
   if (i == nums.length) // 考虑完所有的元素
      if (满足题目条件)
         result.add(路径)
      return

   在 路径 中记录选择
   dfs(i+1, nums, cur+nums[i]) // 选择 nums[i]，考虑 nums[i+1]
   // 如果元素可以被重复选择，则选择完 nums[i]，可以继续选 nums[i]，使用下面的语句
   // dfs(i, nums, cur+nums[i])
   在 路径 中撤销选择

   dfs(i+1, nums, cur) // 不选择 nums[i]，考虑 nums[i+1]
}
```

### 经典回溯 VS DFS

**经典回溯是站在“路径”的角度思考，考虑路径上的每一步选择哪个元素；DFS 是站在“备选集”的角度思考，考虑备选集中的每一个元素是否被选中。**

针对备选集有重复的情况 [90.子集II-备选数重复](./回溯/子集/90.子集II-备选数重复.cpp)

- 站在路径的角度思考更容易去重，只需要先将备选数组排序，再保证路径的递归选择树每一层不出现重复的节点即可。
- 如果站在选择集的角度，只能在最后将 tracking 加入结果集时手动判断重复，容易超过时间限制。

在组合问题中，经典回溯和 DFS 函数的定义都需要一个 index 参数 [39.组合总和-被选数唯一-重复选择](./回溯/组合/39.组合总和-被选数唯一-重复选择.cpp)

- 经典回溯中 index 表示这一步中可选元素的范围为 [index, len)，只在备选集的后半部分中选择是为了防止重复选择，每次递归时 index 变化是跳跃递增的
- DFS 中 index 表示当前考虑的是备选集中的第 index 个元素，DFS 方法天生不会选到重复元素，每次递归时 index 变化是连续递增的

## 贪心

### 区间问题

区间问题肯定按照区间的起点或者终点进行 **排序**
所有区间问题类型：

1. **最多不重叠区间** 只有一个会议室，还有若干会议，如何将尽可能多的会议安排到这个会议室里？问最多能开几个会议
   - 原型：一个区间列表，在某个范围内从列表中选择最多的区间，要求所选区间不重叠
   - 解法：将这些会议（区间）按结束时间（右端点）升序排序，贪心选择结束时间最早的。[435.无重叠区间](./贪心/区间问题/435.无重叠区间.cpp) [452.用最少数量的箭引爆气球](./贪心/区间问题/452.用最少数量的箭引爆气球.cpp)
2. **短区间拼接长区间** 给你若干较短的视频片段，和一个较长的视频片段，请你从较短的片段中尽可能少地挑出一些片段，拼接出较长的这个片段，求最少需要的短视频片段数量
   - 原型：一个区间列表，在其中选择区间拼接成大区间，要求选中的区间必须数值连续（即部分重叠）
   - 解法：将这些视频片段（区间）按开始时间（左端点）排序，贪心选择连续且结束时间最晚的。[1024.视频拼接](./贪心/区间问题/1024.视频拼接.cpp)
3. **区间合并** 给你若干区间，请你将所有有重叠部分的区间进行合并，求合并后的区间列表
   - 将这些区间按起点升序终点降序排序，遍历与前一个区间比较，合并交叉的。[56.合并区间](./贪心/区间问题/56.合并区间.cpp)
4. **删除被覆盖区间** 给你若干区间，其中可能有些区间比较短，被其他区间完全覆盖住了，请你删除这些被覆盖的区间，求剩余区间数量
   - 参照上一题的思路，将这些区间按起点升序终点降序排序，遍历与前一个区间比较，依次合并交叉并删除被覆盖，注意这里的合并只是逻辑合并，方便判断覆盖，不影响区间数量。[1288.删除被覆盖区间](./贪心/区间问题/1288.删除被覆盖区间.cpp)
5. **两个区间列表的交集** 有两个部门同时预约了同一个会议室的若干时间段，请你计算会议室的冲突时段。
   - 原型：两个区间列表，列表内区间不重叠，求两个列表间的区间交集
   - 解法：将这些区间按起点升序排序，双指针依次遍历两个列表，求区间交集。[986.区间列表的交集](./贪心/区间问题/986.区间列表的交集.cpp)
6. **区间重叠** 给你输入若干形如 [begin, end] 的区间，代表若干会议的开始时间和结束时间，请你计算至少需要申请多少间会议室。
   - 原型：一个区间列表，求同一时刻 **最多** 有几个区间重叠
   - 解法：将起点和终点都投影到时间轴上，遍历所有时间点，遇到起点就+1，遇到终点就-1。[253.会议室II](./贪心/区间问题/253.会议室II.cpp)

## 其他

### 循环数组问题的处理

数组中相邻元素构成某种限制，一个循环数组

- 添加法。首部补充原尾部元素，尾部补充原首部元素，基本方法不变，最后的结果除去添加到额外元素 [135.分发糖果](./data_structure/数组&字符串/135.分发糖果.cpp)
- 删除法。要求 [0,n-1]，循环数组中 0 和 n-1 不能同时选中，则可分别计算 [0,n-2] 和 [1,n-1] 求得最大值 [213.打家劫舍-循环数组](./dp/复杂背景/打家劫舍/213.打家劫舍-循环数组.cpp)

### 无穷大

题解算法中通常使用 `0x3f3f3f3f` 表示 INT 范围内的无穷大，这会带来以下几个好处：

1. `0x3f3f3f3f` 的十进制是 1061109567，也就是 10^9 级别的（和 0x7fffffff 一个数量级），而一般场合下的数据都是小于 10^9 的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。
2. 满足“无穷大加一个有穷的数依然是无穷大”：由于一般的数据都不会大于 10^9，所以当我们把 `0x3f3f3f3f` 加上一个数据时，它并不会溢出。
3. 满足“无穷大加无穷大还是无穷大”：事实上 `0x3f3f3f3f+0x3f3f3f3f=2122219134`，这非常大但却没有超过 32-bit int 的表示范围。
4. 如果我们想要将某个数组清零，我们通常会使用 `memset(a,0,sizeof(a))` 这样的代码来实现。但是当我们想将某个数组全部赋值为无穷大时（例如解决图论问题时邻接矩阵的初始化），就不能使用 memset 函数而得自己写循环了，这是因为 memset 是按字节操作的，它能够对数组清零是因为 0 的每个字节都是 0。然而如果我们将无穷大设为 `0x3f3f3f3f`，因为 `0x3f3f3f3f` 的每个字节都是 `0x3f`，所以要把一段内存全部置为无穷大，我们只需要 `memset(a,0x3f,sizeof(a))`。

所以在通常的场合下，`const int INF = 0x3f3f3f3f;` 真的是一个非常棒的选择。

### C++ 常用 API

数字转字符串 `string to_string (int val);`
字符串转数字 `int stoi(const std::string& str, std::size_t* pos = 0, int base = 10)`
           `int atoi(const char *str);`
字符大小写转换 `int tolower( int ch );` `int toupper( int ch )`
判断字符是否是字母 `int isalpha( int ch );`
判断字符是否是数字 `int isdigit( int ch );`
``` c++
// 小顶堆
priority_queue<int, vector<int>, std::greater<int>> heap;
// 自定义比较函数的堆
auto cmp = [](T a, T b) { return a < b; };
priority_queue<T, vector<T>, decltype(cmp) > pq(cmp);
```

## TODO

KMP
[【宫水三叶】简单题学 KMP 算法](https://leetcode-cn.com/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/) 
[有限状态机之 KMP 字符匹配算法](https://labuladong.gitee.io/algo/3/26/94/)
