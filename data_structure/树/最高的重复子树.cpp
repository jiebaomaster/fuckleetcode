/**
 * 652 题的变体：在一个由数组给出的树中寻找最高的重复子树
 * 在数组中可以由下标的关系计算左右子树的位置
 * 最高的子树序列化后的字符串也最长
 */
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

unordered_map<string, int> times;
string maxStr;
int maxLen;
int maxIndex;

// 计算每一棵子树的序列化值
string seq(vector<char> &nums, int i) {
  if (i >= nums.size() || nums[i] == 'n') return "null";
  string res(1, nums[i]);
  string left = seq(nums, i * 2);
  string right = seq(nums, i * 2 + 1);
  res += "," + left + "," + right;
  if (times[res]++ == 1) {
    // 计算最大的重复子树
    if (maxLen < res.size()) {
      maxIndex = i; // 记录最大重复子树的根节点下标
      maxLen = res.size();
    }
  }
  return res;
}

int main() {
  string s;
  // 输入是如下的字符串
  // [1,2,3,1,null,2,null,null,null,null,null,1,null,null,null]
  getline(cin, s);
  times.clear();
  maxStr.clear();
  maxIndex = 0;
  maxLen = 0;
  // 将字符串转化为数组，使得可以用下标访问左右子树
  vector<char> nums;
  nums.push_back(1);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'n') {
      nums.push_back('n');
    } else if (s[i] > '0' && s[i] <= '9') {
      nums.push_back(s[i]);
    }
  }
  seq(nums, 1);
  queue<int> q;
  // 由根节点下标遍历最大的重复子树
  q.push(maxIndex);
  string res = "[";
  bool hasNotNull = true; // 输出满二叉树，
  while (!q.empty() && hasNotNull) {
    hasNotNull = false;
    string tmp;
    for (int i = q.size(); i > 0; i--) {
      int t = q.front();
      q.pop();
      if (nums[t] == 'n')
        tmp += "null,";
      else {
        tmp += string(1, nums[t]) + ",";
        hasNotNull = true;
      }

      // left
      if (t*2 < nums.size())
        q.push(t * 2);
      // right
      if (t*2+1 < nums.size())
        q.push(t * 2 + 1);
    }
    if (hasNotNull) {
      res += tmp;
    }
  }
  res.resize(res.size() - 1);
  res += ']';
  cout << res << "\n";

  return 0;
}