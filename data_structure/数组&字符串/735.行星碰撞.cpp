/**
 * https://leetcode-cn.com/problems/asteroid-collision/
 * 方法一：标记位置是否已被撞毁，在进行碰撞时跳过已经撞毁的位置
 */
class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<bool> used(asteroids.size(), false);  // 改位置是否已撞毁
    // 遍历数组，遇到负数时进行一次连续的向左撞击
    for (int i = 0; i < asteroids.size(); i++) {
      if (asteroids[i] >= 0) {
        continue;
      }
      // 向左寻找正数撞击
      for (int j = i - 1; j >= 0; j--) {
        if (used[j]) continue;  // 已撞毁的不考虑
        if (asteroids[j] < 0)  // 遇到负数，即已经没有正数了，停止
          break;

        if (asteroids[j] + asteroids[i] == 0) {  // 撞到相同的，停止
          used[i] = true;
          used[j] = true;
          break;
        } else if (asteroids[j] + asteroids[i] < 0) {  // 撞到小的，继续
          used[j] = true;
        } else {  // 撞到大的，停止
          used[i] = true;
          break;
        }
      }
    }
    vector<int> ret;
    // 输出还没被撞毁的数
    for (int i = 0; i < asteroids.size(); i++) {
      if (!used[i]) ret.push_back(asteroids[i]);
    }
    return ret;
  }
};

/**
 * 方法二：使用一个栈保存还未撞毁的陨石
 */
class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> remains;  // 栈，保存还未撞毁的陨石
    for (int i = 0; i < asteroids.size(); i++) {
      if (asteroids[i] >= 0) {
        remains.push_back(asteroids[i]);
        continue;
      }
      // 负数，撞击栈中的数字
      bool used = false;  // 标记 i 是否撞毁
      while (!remains.empty()) {
        int top = remains[remains.size() - 1];  // 撞击栈顶
        if (top < 0)  // 遇到负数，即已经没有正数了，停止
          break;

        if (top + asteroids[i] == 0) {  // 撞到相同的，停止
          remains.resize(remains.size() - 1);
          used = true;
          break;
        } else if (top + asteroids[i] < 0) {  // 撞到小的，继续
          remains.resize(remains.size() - 1);
        } else {  // 撞到大的，停止
          used = true;
          break;
        }
      }

      if (!used)  // i 未撞毁，入栈
        remains.push_back(asteroids[i]);
    }

    return remains;
  }
};