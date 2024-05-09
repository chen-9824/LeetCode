//
// Created by cfan on 2024/4/10.
//

#ifndef LEETCODE_INCLUDE_344_H_
#define LEETCODE_INCLUDE_344_H_

/*344. 反转字符串
    简单
提示
    编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。*/

class Solution_344 {
 public:
  void reverseString(vector<char>& s) {
      int left = 0;
      int right = s.size() - 1;
      while (left < right){
          char temp = s[left];
          s[left] = s[right];
          s[right] = temp;
          left += 1;
          right -=1;
      }
  }
};

#endif //LEETCODE_INCLUDE_344_H_
