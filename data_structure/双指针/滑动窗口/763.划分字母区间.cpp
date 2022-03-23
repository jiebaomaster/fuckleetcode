/**
 * https://leetcode-cn.com/problems/partition-labels/
 * 方法一：滑动窗口模拟
 */
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> ret;
    unordered_map<char, int> times; // 每个字符出现的次数
    unordered_set<char> window; // 记录滑动窗口中的字符
    for (int i = 0; i < s.size(); i++) times[s[i]]++;

    int l = 0, r = 0;
    while (r < s.size()) {
      if (window.find(s[r]) == window.end()) {
        window.insert(s[r]);
      }
      times[s[r]]--; // 更新字符 s[r] 剩余出现的次数
      // 字符 s[r] 在后续字符串中不出现了，说明所有 s[r] 字符都在窗口中了
      if (times[s[r]] == 0) {
        window.erase(s[r]); // 满足条件的字符退出窗口
         // 窗口为空，说明所有在窗口中出现过的字符都满足条件了，进行划分
        if (window.empty()) {
          ret.push_back(r - l + 1);
          l = r + 1;
        }
      }
      r++;
    }
    return ret;
  }
};

/**
 * 方法二：动态更新划分的最后位置
 */
class Solution1 {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        unordered_map<char, int> last; // 每个字符最后出现的位置
        for(int i = 0; i < s.size(); i++)
            last[s[i]] = i;
        
        int l = 0, r = 0;
        int end = 0; // 划分的最后位置
        while(r < s.size()) {
            // 动态更新划分的最后位置
            // 划分的最后位置应该是划分中所有字符最后出现的位置
            end = max(end, last[s[r]]);
            if(r == end) { // 当前到达最后位置了，进行一次划分
                ret.push_back(r-l+1);
                l = r+1;
            }
            r++;
        }
        return ret;
    }
};