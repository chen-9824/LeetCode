//
// Created by cfan on 2024/4/15.
//

#ifndef LEETCODE_INCLUDE_20_H_
#define LEETCODE_INCLUDE_20_H_
/*

20. 有效的括号
    简单
提示
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/
#include <stack>
class Solution_20 {
 public:
  /*
   * 匹配的时候是先进后出
   */
  bool isValid(string s) {
      if (s.size() % 2 != 0)
          return false;

      stack<char> record;
      for (auto i : s) {
          if (i == '(' || i == '[' || i == '{') {
              record.push(i);
              continue;
          }

          if (record.empty())
              return false;

          if (i == ')') {
              if (record.top() == '(')
                  record.pop();
              else
                  return false;
          } else if (i == ']') {
              if (record.top() == '[')
                  record.pop();
              else
                  return false;
          } else if (i == '}') {
              if (record.top() == '{')
                  record.pop();
              else
                  return false;
          }
      }
      return record.empty();
  }
};

#endif //LEETCODE_INCLUDE_20_H_
