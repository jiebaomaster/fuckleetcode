/**
 * https://leetcode-cn.com/problems/sort-colors/
 * 荷兰国旗问题，将数组中的 0，1，2 分别归类放置在数组的前中后三部分
 * 方法一：两次遍历，先处理 0，再处理 1，最后 2 不用特殊处理
 */
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int p = 0;
    // p 指向可以放置 0 的位置
    // 遍历整个数组，将 0 放置到数组到最前面
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        swap(nums[p], nums[i]);
        p++;
      }
    }
    // 此时 p 之前全是 0，p 指向可以放置 1 的位置
    // 遍历 p 之后的数组，将 1 放置到数组的中间部分
    for (int i = p; i < nums.size(); i++) {
      if (nums[i] == 1) {
        swap(nums[p], nums[i]);
        p++;
      }
    }
  }
};

/**
 * 方法二：双指针，一次遍历
 */
class Solution1 {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    for (int i = 0; i <= r; i++) {
      while (i <= r && nums[i] == 2) {
        swap(nums[i], nums[r]);
        r--;
      }
      if (nums[i] == 0) {
        swap(nums[i], nums[l]);
        l++;
      }
    }
  }
};

/**
 * 方法三：两次遍历，直接计算 0，1，2 的数量，重新构建数组
 */
class Solution2 {
 public:
  void sortColors(vector<int>& nums) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    // 计算 0，1，2 的数量
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        cnt0++;
      else if (nums[i] == 1)
        cnt1++;
      else
        cnt2++;
    }
    // 重新构建数组
    for (int i = 0; i < nums.size(); i++) {
      if (cnt0-- > 0)
        nums[i] = 0;
      else if (cnt1-- > 0)
        nums[i] = 1;
      else
        nums[i] = 2;
    }
  }
};