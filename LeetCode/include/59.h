//
// Created by cfan on 2024/4/7.
//

#ifndef LEETCODE_INCLUDE_59_H_
#define LEETCODE_INCLUDE_59_H_

/*59. 螺旋矩阵 II
中等
    给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。*/

class Solution_59 {
 public:
  vector<vector<int>> generateMatrix(int n) {
      int count = 1;
      int loop = n / 2;//每次循环每个边少两列
      int mid = n / 2;
      int current_loop = 1;
      int start_x = 0;
      int start_y = 0;
      vector<vector<int>> res(n, vector<int>(n, 0));
      int i, j;
      while (current_loop <= loop){
          i = start_x;//起点，每次循环每条边起点互相配合
          j = start_y;
          for(j = start_y; j < n - current_loop; ++j){
              res[i][j] = count++;
          }

          for(i = start_x; i < n - current_loop; ++i){
              res[i][j] = count++;
          }

          for(; j > start_y; --j){
              res[i][j] = count++;
          }

          for(; i > start_x; --i){
              res[i][j] = count++;
          }

          start_x++;
          start_y++;

          current_loop += 1;
      }
      if(n % 2)//奇数中间有数
          res[mid][mid] = count;
      return res;
  }
};

#endif //LEETCODE_INCLUDE_59_H_
