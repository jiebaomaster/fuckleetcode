class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> s; // 单调栈，栈底到栈顶递减
        unordered_map<int, int> num_greater;
        for(const auto n : nums2) {
            while(!s.empty() && n > s.top()) {
                num_greater.insert({s.top(), n});
                s.pop();
            }
            s.push(n);
        }

        for(int i = 0; i < nums1.size(); i++) {
            res[i] = num_greater[nums1[i]] ? num_greater[nums1[i]] : -1;
        }

        return res;
    }
};

/**
 * https://leetcode-cn.com/problems/next-greater-element-i/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dan-tiao-zhan#dan-tiao-zhan-mo-ban
 * 单调栈用途不太广泛，只处理一种典型的问题，叫做 Next Greater Element
 * https://github.com/jiebaomaster/kaoyan/blob/master/data_structure/monotonyStack.cpp
 */