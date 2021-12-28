/**
 * https://leetcode-cn.com/problems/subsets/
 * 
 * 回溯的思想：
 * 先求 nums[0] 开始的集合，再求 nums[1] 开始的集合...
 * 若 set[0] 为 nums[i]，则 set[1] 是 nums[i+1]~nums[len-1] 时可以保证不重复
 * 
 */
class Solution {
public:
  vector<vector<int>> res; // 结果集
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    backtracking(track, 0, nums);
    return res;
  };
    
  // 考虑 track[d] 的所有选择，d 为当前递归层数
  void backtracking(vector<int> &track, int start, vector<int>& nums) {
    // 把递归路径上的所有临时结果都保存到结果集
    res.push_back(track);

    for(int i = start; i < nums.size(); i++) { // 遍历位置 start 的所有选择
      track.push_back(nums[i]);
      // 考虑 track[d+1] 的所有选择 nums[i+1...]
      backtracking(track, i+1, nums);
      track.pop_back();
    }  
  };
};

/**
 * @brief dfs 回溯
 * 求子集时，依次考虑每一个nums[i]，可以选择nums[i]，也可以不选择，记录在 track 中
 * 考虑完所有的元素选择后，当前的 track 就是子集
 */
class Solution1 {
public:
  vector<vector<int>> res; // 结果集
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    dfs(track, 0, nums);
    return res;
  };
    
  void dfs(vector<int> &track, int start, vector<int>& nums) {
    if(start == nums.size()) { // nums 中的每一个数都考虑过了
      res.push_back(track);
      return;
    }

    // 选择 nums[i]
    track.push_back(nums[start]);
    dfs(track, start+1, nums);
    track.pop_back();

    // 不选择 nums[i]
    dfs(track, start+1, nums);
  };
};

/**
 * 实际由数学归纳法可以发现 nums[0...i] 的子集 subset(nums[0...i]) 等于
 * subset(nums[0...i-1]) + foreach(subset(nums[0...i]),(e){e.push(nums[i])} )
 * 
 * 例如：如果 A = subset([1,2]) ，那么：
 * subset([1,2,3])= A + [A[i].add(3) for i = 1..len(A)]
 */
class Solution2 {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) return {{}};

    int n = nums.back(); // 把最后一个元素拿出来
    nums.pop_back();
    // 先递归算出前面元素的所有子集s
    vector<vector<int>> pre_subsets = subsets(nums);

    int size = pre_subsets.size();
    for (int i = 0; i < size; i++) {
      // 然后在之前的结果之上追加
      pre_subsets.push_back(pre_subsets[i]);
      pre_subsets.back().push_back(n);
    }
    return pre_subsets;
  }
};

