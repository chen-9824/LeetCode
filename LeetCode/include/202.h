//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_202_H_
#define LEETCODE_INCLUDE_202_H_
/*202. 快乐数
    简单
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 提示：
1 <= n <= 2^31 - 1
 */
#include <unordered_set>
class Solution_202 {
 public:
  int getSum(int n) {
      int sum = 0;
      while (n != 0) {
          sum += (n % 10) * (n % 10);
          n = n / 10;
      }
      return sum;
  }
  //时间复杂度: O(logn)
  //空间复杂度: O(logn)
  bool isHappy(int n) {
      unordered_set<int> record_set;
      int sum = 0;
      while (1) {
          sum = getSum(n);

          if(sum == 1)
              return true;

          if (record_set.find(sum) != record_set.end())
              return false;
          else
              record_set.insert(sum);
          n = sum;
      }
  }
};

#endif //LEETCODE_INCLUDE_202_H_
