//
// Created by cfan on 2024/4/10.
//

#ifndef LEETCODE_INCLUDE_541_H_
#define LEETCODE_INCLUDE_541_H_

/*541. 反转字符串 II
简单
    给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。*/
#include <algorithm>
class Solution_541 {
 public:
  /*
   * 循环步长改为2k就可以
   */
  string reverseStr(string s, int k) {

      for (int i = 0; i < s.size(); i += (2 * k)) {
          if (i + k <= s.size()) {
              reverse(s.begin() + i, s.begin() + i + k);
          } else {
              reverse(s.begin() + i, s.end());
          }
      }
      return s;
  }
};

#endif //LEETCODE_INCLUDE_541_H_
