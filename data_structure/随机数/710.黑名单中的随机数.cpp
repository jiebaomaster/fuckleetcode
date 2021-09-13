/**
 * https://leetcode-cn.com/problems/random-pick-with-blacklist/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/sui-ji-ji-he#bi-kai-hei-ming-dan-de-sui-ji-shu
 */
class Solution {
 public:
  Solution(int n, vector<int>& blacklist) {
    sz = n - blacklist.size();

    /**
     * 应将黑名单中的数和数组后半段的非黑名单数交换，这样取随机数的时候就可以直接从数据集的前段有效部分获取
     * |  *  **   |  * |
     *   有效部分   所有黑名单中的数集中在数据集后半段的无效部分
     * |          |****|
     */
    unordered_map<int, int> setted;
    // 记录已经在数据集无效部分的黑名单数，这些数的位置不能用于交换
    for (const auto num : blacklist)
      if (num >= sz && num <= n - 1) {
        setted[num]++;
      }

    int right = n - 1;  // 记录数据集无效部分中，下一个可以用于交换的位置
    for (const auto num : blacklist) {
      // 只处理数据集有效部分的黑名单数，从无效部分选择一个非黑名单数与其交换
      if (num >= 0 && num < sz) {
        while (setted.count(right)) {  // 找到一个可用于交换的位置
          right--;
        }
        index_val[num] = right;  // 保存黑名单数的被替换后的值
        setted[right]++;
        right--;
      }
    }
  }

  int pick() {
    int index = rand() % sz;  // 获取一个随机索引
    if (index_val.count(index))  // 如果获取到的索引是黑名单中的数，返回其逻辑值
      return index_val[index];
    else
      return index;
  }

 private:
  int sz;  // 除去黑名单后，实际数据集大小
  unordered_map<int, int>
      index_val;  // 黑名单的位置=>逻辑有效值，保证实际数据集的逻辑连续
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */