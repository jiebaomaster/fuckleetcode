/**
 * https://leetcode-cn.com/problems/number-of-atoms/
 * 类似于 394题 碰到括号用一般用栈处理
 */
class Solution {
 public:
  string countOfAtoms(string formula) {
    stack<pair<string, int>> st;
    vector<pair<string, int>> tmp;
    for (int i = 0; i < formula.size();) {
      if (formula[i] == '(') { // ( 左括号直接入栈
        st.push({"(", -1});
        i++;
      } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
        // 大写字母，处理原子原子和次数
        int s = i;
        i++;
        if (formula[i] >= 'a' && formula[i] <= 'z') i++;
        string name = formula.substr(s, i - s);
        int time = getTime(formula, i);
        st.push({name, time});
      } else {  // )
        i++;
        int time = getTime(formula, i);
        // 两个括号内的原子进行重复
        while (st.top().first != "(") {
          // in
          auto a = st.top();
          st.pop();
          a.second *= time;
          tmp.push_back(a);
        }
        st.pop();  // "("
        // 重复完之后重新入栈
        for (int j = 0; j < tmp.size(); j++) {
          st.push(tmp[j]);
        }
        tmp.clear();
      }
    }

    // 利用map合并同类项，由于map是红黑树，保证拼接输出时按字典序
    map<string, int> atoms;
    while (!st.empty()) {
      auto t = st.top();
      st.pop();
      atoms[t.first] += t.second;
    }
    // 拼接输出
    string res;
    for (auto i = atoms.begin(); i != atoms.end(); i++) {
      res += i->first;
      if (i->second > 1) res += to_string(i->second);
    }
    return res;
  }
  // 从字符串中提取数字
  int getTime(string &s, int &i) {
    int ret = 0;
    while (i < s.size() && isdigit(s[i])) {
      ret = ret * 10 + (s[i] - '0');
      i++;
    }
    return ret ? ret : 1;
  }
};