/**
 * https://leetcode-cn.com/problems/move-zeroes/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-3/mu-lu-ye-2/yuan-di-xiu-gai-shu-zu#yi-dong-ling
 * 题目让我们将所有 0 移到最后，其实就相当于移除 nums 中的所有 0，然后再把后面的元素都赋值为 0 即可。
 */ 
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() < 2) return;

    // 原地删除数组中所有的 0
    int slow = -1, fast = 0;
    while (fast < nums.size()) { 
      if (nums[fast] != 0) {
        nums[++slow] = nums[fast];
      }
      fast++;
    }
    
    // 将后面 (slow, nums.size()) 的元素全部赋值为 0
    for (slow++; slow < nums.size(); slow++) nums[slow] = 0;
  }
};

/**
 * 方法二：冒泡
 * 将所有的 0 冒泡到数组尾部
 */ 
class Solution1 {
 public:
  void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size() - cnt;) {
      if (nums[i] != 0) {
        i++;
        continue;
      }
      for (int j = i; j < nums.size() - cnt - 1; j++) {
        swap(nums[j], nums[j + 1]);
      }
      cnt++;
    }
  }

  void moveZeroes(vector<int>& nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[right] != 1 && nums[right] != 6 && nums[right] != 3) {
        for (int i = right; i > left; i--) {
          swap(nums[i], nums[i - 1]);
        }
        left++;
      }
      ++right;
    }
  }
};

/**
 * 变形题：移动 1、6、3 到数组末尾，且保持相对顺序
 * 类似上面的冒泡思想，关键在于保持两部分的顺序
 * 
 * 可以从前往后遍历，然后将非 163 向前冒泡
 * 也可以从后往前遍历，然后将 163 向后冒泡
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) { // 从左往右遍历
      if (nums[right] != 1 && nums[right] != 6 && nums[right] != 3) {
        for (int i = right; i > left; i--) { // 将非 163 往前冒泡
          swap(nums[i], nums[i - 1]);
        }
        left++;
      }
      ++right;
    }
  }
};