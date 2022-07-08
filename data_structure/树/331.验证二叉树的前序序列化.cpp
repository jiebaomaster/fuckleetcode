/**
 * https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/
 * https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/solution/pai-an-jiao-jue-de-liang-chong-jie-fa-zh-66nt/
 * 
 * 方法一：栈模拟
 * 自底向上，消去所有叶子节点，用栈模拟自底向上的过程
 * 1. 叶子节点是最容易判断符和要求的，只要是 x,#,# 即可
 * 2. 当一个节点不是叶子节点的时候，有两种情况：
 *      两个孩子都非"#"（空）
 *      一个孩子为"#"（空），另一个孩子非"#"（空）
 * 为了兼容这两个情况，把有效的叶子节点使用 "#" 代替。 
 * 比如把 4## 替换成 # 。此时，叶子节点会变成空节点！
 * 这样只需要一直消去叶子节点就可以了，不需要额外考虑非叶子节点
 */
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    vector<char> st; // 栈，存储还未判断的节点
    for (int i = 0; i < preorder.size(); i++) {
      if (preorder[i] == ',') continue;
      if (isdigit(preorder[i])) { // 数字
        // 有可能是多位数，最低位进栈就可以了，跳过前面的位
        while (isdigit(preorder[i])) {
          i++;
        }
        i--;
      }
      st.push_back(preorder[i]);
      // 栈中 x,#,# 即出现一个叶子节点，符和条件
      // 消去一个叶子节点时，压入 # 可能会产生新的叶子节点，这里用循环消去所有
      while (st.size() > 2 && st.back() == '#' && st[st.size() - 2] == '#' &&
             st[st.size() - 3] != '#') {
        st.pop_back();
        st.pop_back();
        st.pop_back();
        st.push_back('#'); // 用一个的 # 代替符和条件的叶子节点
      }
    }
    // 最后栈中剩下一个 #
    return st.size() == 1 && st.back() == '#';
  }
};