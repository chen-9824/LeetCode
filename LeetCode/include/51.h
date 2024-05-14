//
// Created by cfan on 2024/5/14.
//

#ifndef LEETCODE_INCLUDE_51_H_
#define LEETCODE_INCLUDE_51_H_

/*
 * 51. N 皇后
困难

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 */

class Solution_51 {
 public:
  bool is_valid(int row, int col, vector<string> &chessboard, int n){
      //判断列
      for(int i = 0; i < row; i++){
          if(chessboard[i][col] == 'Q')
              return false;
      }

      //45度角
      for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
          if(chessboard[i][j] == 'Q')
              return false;
      }

      //135度角
      for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
          if(chessboard[i][j] == 'Q')
              return false;
      }

      return true;
  }
  vector<vector<string>> res;
  vector<string> path;
  void back(int n, int row){
      if(row == n) {
          res.push_back(path);
          return;
      }
      for(int i = 0; i < n; i++){
          if(is_valid(row, i, path, n)){
              path[row][i] = 'Q';
              back(n, row + 1);
              path[row][i] = '.';
          }
      }
  }
  vector<vector<string>> solveNQueens(int n) {

      path = vector<string>(n, string(n, '.'));
      back(n, 0);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_51_H_
