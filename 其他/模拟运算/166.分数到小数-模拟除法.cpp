class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    // 转化成long，处理溢出
    long num = numerator;
    long deno = denominator;
    // 可以整除的直接返回
    if (num % deno == 0) return to_string(num / deno);
    // 处理负数，最终要转化成两个正数相除
    bool nagitive = false;
    if (num < 0) {
      nagitive = true;
      num *= -1;
    }
    if (deno < 0) {
      nagitive = !nagitive;
      deno *= -1;
    }
    // 拼接正负和整数部分
    string res = (nagitive ? "-" : "") + to_string(num / deno) + ".";

    // 余数进行小数部分的除法
    num %= deno;
    // 被除数出现的位置，当出现重复的被除数，说明存在循环小数
    unordered_map<long, int> num_index;  
    int i = res.size();
    while (num) { // 一直除到为0
      // 出现重复的被除数，被除数出现的位置到当前位置是循环小数
      if (num_index.count(num)) {
        res.insert(res.begin() + num_index[num], '(');
        res += ')';
        break;
      }
      num_index[num] = i++;
      num *= 10; // 进一位，再除
      // 保存本位的除法结果
      res.push_back('0' + num / deno);
      // 下一个被除数
      num %= deno;
    }
    return res;
  }
};