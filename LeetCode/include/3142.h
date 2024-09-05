//
// Created by cfan on 2024/8/29.
//

#ifndef LEETCODE_INCLUDE_3142_H_
#define LEETCODE_INCLUDE_3142_H_
/*
3142. 判断矩阵是否满足条件
简单
提示
    给你一个大小为 m x n 的二维矩阵 grid 。你需要判断每一个格子 grid[i][j] 是否满足：
如果它下面的格子存在，那么它需要等于它下面的格子，也就是 grid[i][j] == grid[i + 1][j] 。
如果它右边的格子存在，那么它需要不等于它右边的格子，也就是 grid[i][j] != grid[i][j + 1] 。
如果 所有 格子都满足以上条件，那么返回 true ，否则返回 false 。

 提示：
1 <= n, m <= 10
0 <= grid[i][j] <= 9
*/

class Solution_3142 {
 public:
  bool satisfiesConditions(vector<vector<int>>& grid) {
      if(grid.empty()){
          return false;
      }
      for(int i = 0; i < grid.size(); ++i){
          for(int j = 0; j < grid[0].size(); ++j){
              if(i < grid.size() - 1) {
                  if (grid[i][j] != grid[i + 1][j])
                      return false;
              }
              if(j < grid[0].size() - 1) {
                  if (grid[i][j] == grid[i][j + 1])
                      return false;
              }
          }
      }
      return true;
  }
};

#endif //LEETCODE_INCLUDE_3142_H_
