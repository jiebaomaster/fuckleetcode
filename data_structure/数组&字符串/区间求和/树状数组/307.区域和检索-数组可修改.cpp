/**
 * https://leetcode.cn/problems/range-sum-query-mutable/
 * 单点更新，区间查询
 * 方法一：
 */
class NumArray {
  class BinaryIndexTree { // 树状数组
    vector<int>& nums;
    vector<int> c; // c 维护一些区间的和，c[i] = (n[i]-lowbit(i), n[i]]
    static int lowbit(int x) { return x & (-x); }
    void add(int index, int val) {
      // 从 index 开始到 c 数组尾部，所有包含 i 的区间都要加上 val
      for (int i = index; i <= nums.size(); i += lowbit(i)) c[i] += val;
    }
    // 查询区间 [0,index] 的和
    int query(int index) {
      int res = 0;
      // 从 index 开始到 c 数组首部，累加所有 0～index 内的区间 c[i]
      for (int i = index; i; i -= lowbit(i)) res += c[i];

      return res;
    }

   public:
    BinaryIndexTree(vector<int>& nums) : nums(nums) {
      c.resize(nums.size() + 1); // c 的下标从 1 开始，因为 lowbit(0)=0，会造成死循环
      // 建立 c，从 0 开始累加 nums[i]
      for (int i = 1; i <= nums.size(); i++) add(i, nums[i - 1]);
    }
    // 更新数组中的某个值
    void update(int index, int val) {
      add(index + 1, val - nums[index]);
      nums[index] = val;
    }
    // 查询区间 [l,r] 的和
    int query(int l, int r) { return query(r + 1) - query(l); }
  };
  BinaryIndexTree bit;

 public:
  NumArray(vector<int>& nums) : bit(nums) {}

  void update(int index, int val) { bit.update(index, val); }

  int sumRange(int left, int right) { return bit.query(left, right); }
};

/**
 * 方法二：线段树
 */
class NumArray {
  int* p;
  class SegmentTree {  // 线段树
    int* f;  // f[k] 表示 第 k 段区间的区间和，k 从 1 开始
    vector<int>& nums;
    // 构建线段树的第 k 段区间 [l,r]
    void buildTree(int k, int l, int r) {
      if (l == r) {  // 单节点的区间和就是节点值
        f[k] = nums[l - 1];
        return;
      }
      // 递归构建左右区间
      int m = (l + r) >> 1;
      buildTree(k + k, l, m);
      buildTree(k + k + 1, m + 1, r);
      f[k] = f[k + k] + f[k + k + 1];
    }
    // 向第 k 段区间 [l,r] 中的节点 i 加上 n
    void add(int k, int l, int r, int i, int n) {
      f[k] += n;  // 从根到叶子节点都要加上 n
      if (l == r) {
        return;
      }
      int m = (l + r) >> 1;
      if (m >= i)  // i 在左半边
        add(k + k, l, m, i, n);
      else  // i 在右半边
        add(k + k + 1, m + 1, r, i, n);
    }
    // 在第 k 段区间 [l,r] 中查找子区间 [x,y] 的区间和
    int calc(int k, int l, int r, int x, int y) {
      if (l == x && r == y) {  // 找到相同区间
        return f[k];
      }

      int m = (l + r) >> 1;
      if (m >= y) {  // [x,y] 落在左半边 [l,m]
        return calc(k + k, l, m, x, y);
      } else if (m < x) {  // [x,y] 落在右半边 [m+1, r]
        return calc(k + k + 1, m + 1, r, x, y);
      } else {  // [x,y] 跨过了左右半边，分别计算 [x,m] 和 [m+1,y]
        return calc(k + k, l, m, x, m) + calc(k + k + 1, m + 1, r, m + 1, y);
      }
    }

   public:
    SegmentTree(vector<int>& nums) : nums(nums) {
      f = new int[nums.size() * 4 + 1];
      buildTree(1, 1, nums.size());
    }
    // 更新数组中的某个值
    void update(int pos, int val) {
      // 向 nums[pos] 加上 val - nums[pos]
      add(1, 1, nums.size(), pos + 1, val - nums[pos]);
      nums[pos] = val;  // 更新 nums
    }
    int calc(int l, int r) { return calc(1, 1, nums.size(), l + 1, r + 1); }
  };

  SegmentTree st;

 public:
  NumArray(vector<int>& nums) : st(nums) {}

  void update(int index, int val) { st.update(index, val); }

  int sumRange(int left, int right) { return st.calc(left, right); }
};