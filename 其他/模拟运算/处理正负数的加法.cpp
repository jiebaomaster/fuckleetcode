#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    if (num1[0] == '-' && num2[0] == '-') {  // 两个负数，使用加法，-(|a|+|b|)
      return "-" + doAdd(num1.substr(1), num2.substr(1));
    } else if (num1[0] == '-' || num2[0] == '-') { // 一个负数，使用减法
      if (num1[0] == '-') {  // b-|a|
        num1 = num1.substr(1);
        if (num1 > num2) {  // -(|a|-b)
          return "-" + doSub(num1, num2);
        } else {  // b-|a|
          return doSub(num2, num1);
        }
      } else {  // a-|b|
        num2 = num2.substr(1);
        if (num1 >= num2) {  // a-|b|
          return doSub(num1, num2);
        } else {  // -(|b|-a)
          return "-" + doSub(num2, num1);
        }
      }
    } else {  // 两个正数，a+b
      return doAdd(num1, num2);
    }
  }

  string doAdd(const string &num1, const string &num2) {
    int l1 = num1.size() - 1;
    int l2 = num2.size() - 1;
    int c = 0;
    string res;
    while (l1 >= 0 || l2 >= 0 || c) {
      if (l1 >= 0) c += num1[l1--] - '0';
      if (l2 >= 0) c += num2[l2--] - '0';
      res = string(1, c % 10 + '0') + res;
      c /= 10;
    }

    return res;
  }
  // 计算 n1 - n2，保证 n1>n2
  string doSub(const string &n1, const string &n2) {
    int l1 = n1.size() - 1;
    int l2 = n2.size() - 1;
    int c = 0;
    string res;
    while (l1 >= 0 || l2 >= 0 || c) {
      int t = n1[l1--] - '0' - c;
      if (l2 >= 0) t -= n2[l2--] - '0';

      if (t < 0) {
        c = 1;
        t += 10; // 负数借位补正
      } else
        c = 0;

      res = to_string(t) + res;
    }
    // 去除前导 0
    int k = 0;
    while(k < res.size()-1) {
      if(res[k] != '0') break;
      k++;
    }

    return res.substr(k);
  }
};

int main() {
  string num1,
        num2;
  Solution s;
  while(1) {
    cin >> num1 >> num2;
    cout << s.addStrings(num1, num2) << endl;
  }
}