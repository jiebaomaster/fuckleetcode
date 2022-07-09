/**
 * https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
 * O(1) 时间等概率返回，必须使用数组存储元素。
 * 列表中的随机删除并不是 O(1) 的。然而列表中元素的顺序是无关紧要的，只要它们正确地
 * 存在于列表中即可。因此，在删除元素时，我们可以将被删的元素与列表中最后一个元素
 * 交换位置，然后删除最后一个元素。
 */
class RandomizedCollection {
  vector<int> nums;
  unordered_map<int, unordered_set<int>> positions;

 public:
  RandomizedCollection() {}

  bool insert(int val) {
    nums.push_back(val);
    positions[val].insert(nums.size() - 1);
    return positions[val].size() == 1;
  }

  bool remove(int val) {
    if (positions[val].empty()) return false;
    int endp = nums.size() - 1;
    auto p = *positions[val].begin();
    if (nums.back() != val) { // 最后一个元素不是 val，交换位置
      // 调整 val 和 尾元素 的位置信息
      positions[nums.back()].erase(endp);
      positions[nums.back()].insert(p);
      positions[val].erase(p);
      positions[val].insert(endp);
      nums[p] = nums[endp];
    }
    // 删除最后一个
    positions[val].erase(endp);
    nums.resize(endp);
    return true;
  }

  int getRandom() { return nums[rand() % nums.size()]; }
};
