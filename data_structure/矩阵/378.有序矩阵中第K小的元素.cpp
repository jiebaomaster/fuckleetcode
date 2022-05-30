/**
 * https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/
 * 在一个行升序 列升序的 n*n 矩阵中查找第 k 小的数
 *
 * 方法一：大顶堆求矩阵前 k 大
 * 时间 O(n^2logk)，每个元素都入堆一次
 * 空间 O(k)，堆的大小始终为 k
 */
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> heap;
    for (auto& row : matrix) {
      for (int n : row) {
        if (k) {
          heap.push(n);
          k--;
        } else {
          if (heap.top() > n) { // 比堆顶小，更新堆
            heap.pop();
            heap.push(n);
          }
        }
      }
    }
    return heap.top();
  }
};

/**
 * 方法二：n 路归并
 * 将矩阵的 n 行进行归并，直到第 k 个
 * 时间 O(klogn)，归并 k 次，每次堆中插入和弹出的操作时间复杂度均为 logn
 * 空间 O(n)，堆的大小始终为 n
 */
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap; // 小顶堆 {值，行}
    int n = matrix.size();
    vector<int> p(n); // 每行中归并到第几个数，即列
    for (int i = 0; i < p.size(); i++) {
      heap.push({matrix[i][p[i]], i});
    }
    while (--k) {
      auto min = heap.top(); // 最小的出队
      heap.pop();
      int i = min.second;
      p[i]++;
      // 本行还没用完，本行中的下一个数入堆
      if (p[i] < n) heap.push({matrix[i][p[i]], i});
    }
    return heap.top().first;
  }
};

/**
 * https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/solution/er-fen-chao-ji-jian-dan-by-jacksu1024/
 * 方法三：值域二分
 * 找出二维矩阵中最小的数 left，最大的数 right，那么第 k 小的数必定在 left ~ right 之间
 * 统计矩阵中不大于 mid 的元素个数 smallerN
 * 如果 smallerN >= mid 说明 mid 太大了，调整上界，反之调整下界
 * 
 * 本题的关键在于行列的有序性使得可以在 O(n) 时间内统计矩阵中不大于 mid 的元素个数
 * 参考第 240 题
 */
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1];
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (cntN(matrix, mid) >= k) {
        r = mid;
      } else
        l = mid + 1;
    }
    return l;
  }

  // 统计矩阵中不大于 n 的元素个数
  int cntN(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int i = n - 1;
    int j = 0;
    int cnt = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= k) {
        j++;
        cnt += i + 1; // 该列中的所有元素都不大于 n
      } else {
        i--;
      }
    }
    return cnt;
  }
};