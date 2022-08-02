/**
 * https://leetcode-cn.com/problems/gas-station/
 * 
 * 汽车进入站点 i 可以加 gas[i] 的油，离开站点会损耗 cost[i] 的油，那么可以把站点和与其相连的路看做一个整体，
 * 将 gas[i] - cost[i] 作为经过站点 i 的油量变化值：题目描述的场景就被抽象成了一个环形数组，
 * 数组中的第 i 个元素就是 gas[i] - cost[i]。
 * 问题转化为判断这个环形数组中是否能够找到一个起点 start，使得从这个起点开始的累加和一直大于等于 0。
 * 
 * https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/
 * 
 * 数形结合的思想，折线图 y=gas[x]-cost[x]
 * 要使从 x 出发能绕行一周，则 y 的任意部分都在 X 轴以上，只要 y 的最低点在 X 轴之上即可
 * 即从 y 的最低点的下一个点出发
 */
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0, minsum = INT_MAX;
    int target = -1;
    for (int i = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i]; // 计算环形数组的最小和
      if (sum < minsum) { // 更新最低点
        minsum = sum;
        target = i + 1;
      }
    }
    // 最后累加和小于0，则总油量小于总消耗量，一定不能满足要求
    if (sum < 0) return -1; 
    return target % gas.size();
  }
};

/**
 * https://leetcode-cn.com/problems/gas-station/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--30/
 * 
 * 本题的暴力解法很容易想到，遍历每一个位置 i 判断从 i 出发能否绕行一周
 * 但是暴力解法会超时，我们可以通过减少遍历点的个数优化时间
 * 
 * 性质：如果从 x 出发最远可到达 y，那么从 z（x<=z<=y）出发必不能达到 y+1
 * 反证法：如果从 z 出发能到达 y+1，又从 x 能到达 z，所有从 x 出发能到达 y+1，矛盾
 * 
 * 由上述性质可知，从 0 出发最远到达 y ，则下一次只需要判断从 y+1 出发能否绕行一周，
 * 直到最后一个元素
 */
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int res = 0;
    int cur = 0; // 从 res 出发的剩余量
    int sum = 0; // 总剩余量
    for (int i = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i];
      cur += gas[i] - cost[i];
      if (cur < 0) { // 走不到下一个了，则假设从下一个节点出发
        res = i + 1;
        cur = 0;
      }
    }
    // 如果存在解，则 保证 它是 唯一 的，所以可以直接返回 res
    return sum < 0 ? -1 : res;
  }
};