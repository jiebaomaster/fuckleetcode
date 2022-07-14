/**
 * https://leetcode-cn.com/problems/sort-an-array/
 * 用任意的方法排序数组
 *
 * 方法一：快速排序
 */
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
  // 快速排序
  void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int p = partition(nums, l, r);
    quickSort(nums, l, p - 1);
    quickSort(nums, p + 1, r);
  }
  int partition(vector<int>& nums, int l, int r) {
    int k = l + rand() % (r - l + 1);  // 产生一个 [l,r] 间的随机数
    swap(nums[k], nums[l]);            // 交换，即随机取得中轴
    int p = nums[l];
    while (l < r) {
      while (l < r && nums[r] >= p) r--;
      nums[l] = nums[r];
      while (l < r && nums[l] <= p) l++;
      nums[r] = nums[l];
    }
    nums[l] = p;
    return l;
  }
};

/**
 * 方法二：归并排序
 */
class Solution1 {
 public:
  vector<int> sortArray(vector<int>& nums) {
    // 归并排序需要额外的辅助空间 O(n)
    vector<int> back(nums.size());
    mergeSort(nums, back, 0, nums.size() - 1);
    return nums;
  }

  void mergeSort(vector<int>& nums, vector<int>& back, int l, int r) {
    if (l >= r) return;
    int s = l;
    // 1. 递归排序前后两半
    int mid = (l + r) / 2;
    mergeSort(nums, back, l, mid);
    mergeSort(nums, back, mid + 1, r);
    // 2. 将前后两半合并到一起
    int ll = l;
    int lr = mid + 1;
    while (ll <= mid && lr <= r) {
      if (nums[ll] < nums[lr]) {
        back[l++] = nums[ll++];
      } else {
        back[l++] = nums[lr++];
      }
    }
    // 3. 有多的也要合并上
    while (ll <= mid) back[l++] = nums[ll++];
    while (lr <= r) back[l++] = nums[lr++];
    // 4. 赋值回原数组
    while (s <= r) {
      nums[s] = back[s];
      s++;
    }
  }
};

/**
 * 方法三：堆排序
 */
class Solution2 {
 public:
  vector<int> sortArray(vector<int>& nums) {
    heapSort(nums);
    return nums;
  }

  void heapSort(vector<int>& nums) {
    int len = nums.size();
    buildHeap(nums); // 先建立堆
    for (int i = len - 1; i > 0; i--) {
      swap(nums[0], nums[i]); // 交换堆顶和堆尾
      adjustDown(nums, 0, i - 1); // 重新构建堆
    }
  }
  // 建立堆，对于所有非叶子结点进行向下调整
  void buildHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = (len - 1) / 2; i >= 0; i--) {
      adjustDown(nums, i, len - 1);
    }
  }
  // 大顶堆 向下调整，将 nums[s] 放到正确的位置
  // s 的孩子为 左 2s+1，右 2s+2
  void adjustDown(vector<int>& nums, int s, int e) {
    while ((s + 1) * 2 - 1 <= e) { // 只调整非叶子结点
      int child = (s + 1) * 2 - 1; // s 的左孩子
      // 如果右孩子存在且右孩子更大，选择右孩子
      if (child + 1 <= e && nums[child] < nums[child + 1]) 
        child++;
      if (nums[s] < nums[child]) { // 孩子结点更大，交换父结点和孩子结点
        swap(nums[s], nums[child]);
        s = child; // 接着调整孩子
      } else { // 父结点时最大的，则调整结束
        break;
      }
    }
  }
};