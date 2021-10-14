/**
 * https://leetcode-cn.com/problems/gas-station/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-3/lao-si-ji
 * 汽车进入站点 i 可以加 gas[i] 的油，离开站点会损耗 cost[i] 的油，那么可以把站点和与其相连的路看做一个整体，
 * 将 gas[i] - cost[i] 作为经过站点 i 的油量变化值：题目描述的场景就被抽象成了一个环形数组，
 * 数组中的第 i 个元素就是 gas[i] - cost[i]。
 * 问题转化为判断这个环形数组中是否能够找到一个起点 start，使得从这个起点开始的累加和一直大于等于 0。
 * 
 */
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0, minsum = INT_MAX;
    int target = -1;
    for (int i = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i]; // 计算环形数组的最小和
      if (sum < minsum) { // 
        minsum = sum;
        target = i + 1;
      }
    }
    // 最后累加和小于0，则总油量小于总消耗量，一定不能满足要求
    if (sum < 0) return -1; 
    return target % gas.size();
  }
};