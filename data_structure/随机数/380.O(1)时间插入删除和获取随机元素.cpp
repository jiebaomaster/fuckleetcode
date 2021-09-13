/**
 * https://leetcode-cn.com/problems/insert-delete-getrandom-o1/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/sui-ji-ji-he#shi-xian-sui-ji-ji-he
 */
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (value_index.count(val)) return false;

    value_index[val] = nums.size();
    nums.push_back(val);  // 添加到数组末尾，O(1)
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!value_index.count(val)) return false;

    int index = value_index[val];
    // 如果要删除的不是数组的最后一个元素，将 val 交换到数组末尾
    if (index != nums.size() - 1) {
      swap(nums[index], nums[nums.size() - 1]);
      // 更新原末尾元素 值到索引 的映射关系
      value_index[nums[index]] = index;
    }
    value_index.erase(val);  // 删除目标元素的索引
    nums.pop_back();         // 删除数组中最后一个元素，O(1)
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    // 从数组中随机选择一个元素返回，O(1)
    return nums[rand() % nums.size()];
  }

 private:
  unordered_map<int, int> value_index;  // 值到索引的映射，hash 表支持O(1)时间判断值是否在数组中
  vector<int> nums; // 数组支持 O(1) 时间的随机访问，直接用 hash 表不能等概率随机获取元素
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */