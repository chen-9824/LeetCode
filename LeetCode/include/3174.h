//
// Created by cfan on 2024/9/5.
//

#ifndef LEETCODE_INCLUDE_3174_H_
#define LEETCODE_INCLUDE_3174_H_
/*
 * 3174. 清除数字
简单
提示
给你一个字符串 s 。
你的任务是重复以下操作删除 所有 数字字符：
删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
请你返回删除所有数字字符以后剩下的字符串。

 提示：
1 <= s.length <= 100
s 只包含小写英文字母和数字字符。
输入保证所有数字都可以按以上操作被删除。
 */

class Solution_3174 {
 public:
  string clearDigits(string s) {

      int fastIndex = 0;
      int slowIndex = 0;
      for(; fastIndex < s.size(); fastIndex++){
          if(s[fastIndex] >= '0' && s[fastIndex] <= '9'){
              if(slowIndex > 0)
                  slowIndex -= 1;
          }
          else {
              s[slowIndex] = s[fastIndex];
              slowIndex += 1;
          }
      }

      return s.substr(0, slowIndex);

  }
};
#endif //LEETCODE_INCLUDE_3174_H_
