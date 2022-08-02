/**
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * 方法一：hash
 *  时间复杂度 O(n)
 *  空间复杂度 O(n)
 */
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> n(nums1.begin(), nums1.end());
    vector<int> res;
    for (int t : nums2) {
      if (n.count(t)) {
        res.push_back(t);
        n.erase(t);  // 使用过一次后就删除，排除重复的元素
      }
    }
    return res;
  }
};

/**
 * 方法二：排序+双指针判断，类似归并
 * 时间复杂度 排序 O(nlogn + mlogm)
 * 空间复杂度 O(1)
 */
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0;
    vector<int> res;
    while (i < n && j < m) {
      if (nums1[i] == nums2[j]) {
        res.push_back(nums1[i]); // 相等的即为交集元素
        // 跳过重复数，去重
        i++;
        while (i < n && nums1[i] == nums1[i - 1]) i++;
        j++;
        while (j < m - 1 && nums2[j] == nums2[j - 1]) j++;
      } else if (nums1[i] < nums2[j]) {
        i++;
        while (i < n && nums1[i] == nums1[i - 1]) i++;
      } else {
        j++;
        while (j < m - 1 && nums2[j] == nums2[j - 1]) j++;
      }
    }
    return res;
  }
};

/**
 * 方法三，排序+二分
 */
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int n = nums1.size();
    int m = nums2.size();
    auto t = nums2.begin();
    for (int i = 0; i < n; i++) {
      // 二分，在 nums[2] 中找到第一个大于等于 nums1[i] 的
      t = lower_bound(t, nums2.end(), nums1[i]);
      // 没有找到，那 nums[i] 之后的元素也肯定不重复
      if (t == nums2.end()) break;
      // 找到一个一样的
      if (*t == nums1[i]) res.push_back(nums1[i]);
      // 跳过 nums1 中的重复数
      while (i < n - 1 && nums1[i] == nums1[i + 1]) i++;
    }

    return res;
  }
};