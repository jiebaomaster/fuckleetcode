/**
 * https://leetcode-cn.com/problems/24-game/
 * 4 个数，利用 加减乘除括号 拼凑 24
 *
 * https://leetcode-cn.com/problems/24-game/solution/ying-gai-shi-man-hao-li-jie-de-si-lu-liao-by-xiao_/
 * 回溯法，枚举每一种拼凑组合
 *
 * 游戏的第一步是挑出两个数，算出一个新数替代这两个数。
 * 然后，在三个数中玩 24 点，再挑出两个数，算出一个数替代它们。
 * 然后，在两个数中玩 24 点……
 */
class Solution {
 public:
  bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());

    return backTrack(nums);
  }

  bool backTrack(vector<double>& nums) {
    // 只有一个元素了，说明拼凑完成，判断结果是否等于 24
    if (nums.size() == 1) {
      return abs(nums[0] - 24) < 0.0001;
    }
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        vector<double> newNums;  // 下一次拼凑的备选数字

        // 除了挑选出来做计算的数字，其他的数都作为下一次拼凑的备选数字
        for (int k = 0; k < nums.size(); k++) {
          if (k != i && k != j) newNums.push_back(nums[k]);
        }
        // 将挑选出来的数做计算，计算结果也作为下一次拼凑的备选数字
        double t;
        bool needBackTrack = true;
        for (int k = 0; k < 6; k++) {
          // 尝试每一种计算方法，括号的作用隐藏在加减和乘除的先后中
          switch (k) {
            case 0:  // a+b
              t = nums[i] + nums[j];
              break;
            case 1:  // a-b
              t = nums[i] - nums[j];
              break;
            case 2:  // b-a
              t = nums[j] - nums[i];
              break;
            case 3:  // a*b
              t = nums[i] * nums[j];
              break;
            case 4:  // a/b
              if (nums[j])
                t = nums[i] / nums[j];
              else
                needBackTrack = false;
              break;
            case 5:  // b/a
              if (nums[i])
                t = nums[j] / nums[i];
              else
                needBackTrack = false;
              break;
          }
          newNums.push_back(t);
          if (needBackTrack && backTrack(newNums)) return true;
          newNums.pop_back();
          needBackTrack = true;
        }
      }
    }
    return false;
  }
};


/**
 * 进阶需求，输出所有符合要求的计算表达式
 * 基本思路和上述代码是一致的，
 * 使用一个数组保存每一个数的计算表达式，
 * 在每一步挑选数进行计算的同时，为计算结果保存一个该步计算的表达式
 * 计算表达式跟随数字挑选更新，最终计算结果对应其计算表达式
 */
class Solution {
 public:
  vector<string> res;
  bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());
    vector<string> expression; // 每一个数的计算表达式
    for (auto n : cards) {
      expression.push_back(to_string(n));
    }
    backTrack(nums, expression);

    return true;
  }

  void backTrack(vector<double>& nums, vector<string> expression) {
    if (nums.size() == 1) {
      // 保存符合要求的计算表达式
      if (abs(nums[0] - 24) < 0.0001) res.push_back(expression[0]);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        vector<double> newNums; // 下一次拼凑的备选数字
        vector<string> newExpression; // 下一次拼凑的备选数字对应的计算表达式

        for (int k = 0; k < nums.size(); k++) {
          if (k != i && k != j) {
            newNums.push_back(nums[k]);
            newExpression.push_back(expression[k]);
          }
        }
        double t;
        bool needBackTrack = true;
        for (int k = 0; k < 6; k++) {
          // 尝试每一种计算方法
          // 并为计算结果保存一个该步计算的表达式
          switch (k) {
            case 0:  // a+b
              t = nums[i] + nums[j];
              newExpression.push_back("(" + expression[i] + "+" +
                                      expression[j] + ")");
              break;
            case 1:  // a-b
              t = nums[i] - nums[j];
              newExpression.push_back("(" + expression[i] + "-" +
                                      expression[j] + ")");

              break;
            case 2:  // b-a
              t = nums[j] - nums[i];
              newExpression.push_back("(" + expression[j] + "-" +
                                      expression[i] + ")");

              break;
            case 3:  // a*b
              t = nums[i] * nums[j];
              newExpression.push_back(expression[i] + "*" + expression[j]);

              break;
            case 4:  // a/b
              if (nums[j]) {
                t = nums[i] / nums[j];
                newExpression.push_back("(" + expression[i] + "/" +
                                        expression[j] + ")");
              } else
                needBackTrack = false;
              break;
            case 5:  // b/a
              if (nums[i]) {
                t = nums[j] / nums[i];
                newExpression.push_back("(" + expression[j] + "/" +
                                        expression[i] + ")");
              } else
                needBackTrack = false;
              break;
          }
          newNums.push_back(t);
          if (needBackTrack) {
            backTrack(newNums, newExpression);
            newExpression.pop_back();
          }
          newNums.pop_back();
          needBackTrack = true;
        }
      }
    }
  }
};