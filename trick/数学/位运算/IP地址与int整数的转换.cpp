/**
 * https://www.nowcoder.com/questionTerminal/66ca0e28f90c42a196afd78cc9c496ea
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// IP 转 10 进制数
void ip2l(string &s) {
  stringstream is;
  long a1,a2,a3,a4;
  char dot;
  is << s;
  // 利用字符串流按 . 分割字符串
  is >> a1 >> dot >> a2 >> dot >> a3 >> dot >> a4;
  // 将每一段偏移后拼接在一起
  cout << ((a1 << 24) | (a2 << 16) | (a3 << 8) | a4) << endl;
}
// 10 进制数转 IP
void l2ip(long n) {
  long a1 = (n & 0xff000000) >> 24;
  long a2 = (n & 0x00ff0000) >> 16;
  long a3 = (n & 0x0000ff00) >> 8;
  long a4 = (n & 0x000000ff);
  cout << a1 << "." << a2 << "." << a3 << "." << a4 << endl;
}

int main() {
  string s;
  long l;
  while (cin >> s >> l) {
    ip2l(s);
    l2ip(l);
  }
}