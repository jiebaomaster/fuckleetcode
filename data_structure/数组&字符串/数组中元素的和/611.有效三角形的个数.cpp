/**
 * https://leetcode-cn.com/problems/valid-triangle-number/
 * 如果我们将三条边进行升序排序，使它们满足 a≤b≤c，那么 a+c>b 和 b+c>a 是一定成立的，只需要保证 a+b>c。
 * 
 * 方法一：固定 c，暴力枚举 a b
 * 对于 c 确定的情况下，枚举 [0,c] 内的数，找出所有符合要求的 a b
 * 时间 O(n^3)
 */
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int c = 0; c < n; c++) {
      for (int b = c - 1; b >= 0; b--) {
        for (int a = b - 1; a >= 0; a--) {
          if (nums[a] + nums[b] > nums[c]) res++;
        }
      }
    }

    return res;
  }
};

/**
 * 方法二：固定 a b，二分查找 c
 * 时间 O(n^2logn)
 */
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int a = 0; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        // 在 [b+1, n) 中，二分查找第一个 t，满足 t >= a+b
        // 则 [b+1, t) 中的所有数都可作为满足要求的 c
        int t = nums[a] + nums[b];
        int l = b + 1, r = n;
        while (l < r) {
          int mid = l + (r - l) / 2;
          if (t > nums[mid])
            l = mid + 1;
          else
            r = mid;
        }
        res += r - b - 1;
      }
    }
    return res;
  }
};

/**
 * 方法三：固定 a，双指针查找 b 和 c
 * 因为 a+b>c 当 b 增大时，c也可以进行增大
 * 时间 O(n^2)
 */
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int a = 0; a < n - 2; a++) {
      if (nums[a] == 0) continue; // 0 不能作为三角形的边
      int c = a + 1;
      for (int b = a + 1; b < n; b++) { // 移动 b
        while (c < n && nums[a] + nums[b] > nums[c]) { // 移动 c
          c++;
        }
        // 此时 c 是第一个满足 a+b<=c 的数
        res += c - b - 1;
      }
    }
    return res;
  }
};