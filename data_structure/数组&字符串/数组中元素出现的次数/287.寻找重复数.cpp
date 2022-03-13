/**
 * https://leetcode-cn.com/problems/find-the-duplicate-number/
 * https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
 * 
 * 寻找重复数最简单的就是进行哈希记录每个数出现的次数，空间复杂度为 O(n)
 * 方法一：原地哈希
 * 由题可知 n+1 个整数都在 [1, n] 范围内，原地哈希要求元素下标和元素值相等，
 * 即将 k=nums[i] 放置到 nums[k] 中，如 [1,2,3,4,...,n]。
 * 为数组中的每个位置 i 找到 nums[j]=i，即完成该位置的哈希。若 nums[j] 指向的元素
 * 已经完成哈希，说明有多个 nums[j] 哈希到同一位置，nums[j] 就是重复的数
 */
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size();) {
      if (i == nums[i] - 1) { // 当前位置已哈希完成，跳到下一个位置
        i++;
        continue;
      }

      // nums[i] 处的位置已经完成哈希，找到重复数
      if (nums[i] == nums[nums[i] - 1]) {
        return nums[i];
      } else { // 完成位置 nums[i] - 1 处的哈希
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    return -1;
  }
};

/**
 * 前一种方法修改了数组，违反了条件
 * 方法二：静态链表，即将数组元素值作为指针构成的链表
 * https://leetcode-cn.com/problems/find-the-duplicate-number/solution/287xun-zhao-zhong-fu-shu-by-kirsche/
 * 例如：[1,3,4,2,2] 构成以下链表
 *       1->3->2->4->2
 *                ^__|
 * 可以发现有两个结点指向链表中环的入口结点，则问题转化为找链表中的环
 */
class Solution1 {
 public:
  int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]]; // fast 一次走两步
    } while (fast != slow);
    slow = 0;
    while (fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
};
