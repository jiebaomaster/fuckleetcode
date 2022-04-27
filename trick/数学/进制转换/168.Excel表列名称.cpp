/**
 * https://leetcode-cn.com/problems/excel-sheet-column-title/solution/gong-shui-san-xie-cong-1-kai-shi-de-26-j-g2ur/
 * https://leetcode-cn.com/problems/excel-sheet-column-title/
 * 本质是10进制转26进制，10进制转k进制的方法是「除k取余法」
 * 
 * 1对应A，26对应Z，看起来像是27进位，似乎应该每次余27，每次除以27。
 * 但是，因为1对应A，而27对应的也是A，1%27=1, 27%27=0，同一个A余数不同，构成矛盾。
 * 那么除以26行不行？
 * 1%26=1,27%26=1，看起来这样似乎可以保持一致。
 * 但是当26%26的时候，为0，可是实际的值却为Z，又构成了新的矛盾。
 * 
 * 所以，我们调整对应关系，让0对应A，25对应Z，26对应AA，这样就构成了一个正常的26进位。
 * 这样对于A：0%26=0， 对于AA：26%26=0，在余数这里可以保持一致。
 * 新的对应关系是原先对应关系-1得到，所以在每次操作的时候，都要让columnNumber-1，得到新的对应关系
 */
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string res;
    while (columnNumber) {
      columnNumber--;
      res += columnNumber % 26 + 'A';
      columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};