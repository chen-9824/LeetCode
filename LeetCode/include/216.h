//
// Created by cfan on 2024/5/10.
//

#ifndef LEETCODE_INCLUDE_216_H_
#define LEETCODE_INCLUDE_216_H_


/*
 * 216. 组合总和 III
中等
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
只使用数字1到9
每个数字 最多使用一次
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 */

class Solution_216 {
 public:

  vector<vector<int>> res;
  vector<int> path;
  void back(int k, int n, int cur){
      if(path.size() == k){
          int sum = 0;
          for(auto i : path)
              sum += i;
          if(sum == n) {
              res.push_back(path);
          }
          return;
      }

      for(int i = cur; i <= 9; i++){
          if(i > n)
              return;
          path.push_back(i);
          back(k, n, i + 1);
          path.pop_back();
      }
  }
  vector<vector<int>> combinationSum3(int k, int n) {

      back(k, n, 1);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_216_H_
