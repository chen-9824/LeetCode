//
// Created by cfan on 2024/4/10.
//

#ifndef LEETCODE_INCLUDE_KAMA_54_H_
#define LEETCODE_INCLUDE_KAMA_54_H_

/*54. 替换数字（第八期模拟笔试）
时间限制：1.000S  空间限制：128MB
题目描述
    给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
    例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
输入描述
    输入一个字符串 s,s 仅包含小写字母和数字字符。
输出描述
    打印一个新的字符串，其中每个数字字符都被替换为了number
    输入示例
a1b2c3
    输出示例
anumberbnumbercnumber
    提示信息
数据范围：
1 <= s.length < 10000。*/

/*
 * 数组填充类的问题可以通过扩充数组，并从后向前填充的方法解决，好处
 * 1.不用额外申请空间
 * 2.避免从前向后填充需要移动太多元素
 */

class Solution_kama_54 {
 public:
  string replaceNumber(string s) {
      string res;
      for (auto i : s) {
          if (i >= 'a' && i <= 'z')
              res.append(1, i);
          else {
                  res.append("number");
          }
      }
      return res;
  }

  string replaceNumber_double_pionts(string s) {

      int num_count = 0;
      for (auto i : s) {
          if (i < 'a' || i > 'z')
              num_count += 1;
      }
      s.resize(s.size() + (5 * num_count));
      int left = s.size() - 1 - (5 * num_count);
      int right = s.size() - 1;
      while (left >= 0){
          if(isalpha(s[left])){
              s[right] = s[left];
              right -= 1;
              left -= 1;
          } else{
              s[right--] = 'r';
              s[right--] = 'e';
              s[right--] = 'b';
              s[right--] = 'm';
              s[right--] = 'u';
              s[right--] = 'n';
              left -= 1;
          }
      }
      return s;
  }
};

#endif //LEETCODE_INCLUDE_KAMA_54_H_
