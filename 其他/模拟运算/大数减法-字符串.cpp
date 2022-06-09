/**
 * https://mp.weixin.qq.com/s/RtAoA1hdf0h1PaVxRj_fzA
 */

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief 比较字符串的大小。长度更长的字符串，数一定更大；当长度一样的就去比较字典序。
 * 
 * @return ture = a<b 
 */
bool ALessB(string &a, string &b) {
  if (a.size() == b.size())
    return a < b;
  else
    return a.size() < b.size();
}

string doSubString(string &num1, string &num2) {
  string res;

  int i = num1.size() - 1;  // 被减数
  int j = num2.size() - 1;  // 减数
  int carry = 0;
  while (i >= 0 || j >= 0) {
    int tmp = carry;
    if (i >= 0) tmp += num1[i--] - '0';
    if (j >= 0) tmp -= num2[j--] - '0';
    if (tmp < 0) {
      carry = -1;
      res.push_back((tmp + 10) + '0');
    } else {
      carry = 0;
      res.push_back(tmp + '0');
    }
  }
  reverse(res.begin(), res.end());
  
  //删除前导0，注意边界是res.size()-1！！防止当res为"0000"时，删为""的清空
  int k;
  for(k = 0; k < res.size()-1; k++) {
    if(res[k] != '0') break;
  }

  return res.substr(k);
}

/**
 * @brief 计算 num1-num2
 */
string subString(string &num1, string& num2) {
  if (ALessB(num1, num2)) { // num1<num2 时，结果为 -(num2-num1)
    return "-" + doSubString(num2, num1);
  } else {
    return doSubString(num1, num2);
  }
}

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  cout << subString(num1, num2) << endl;
}