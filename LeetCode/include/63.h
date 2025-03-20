/*
63. 不同路径 II
中等
提示
给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。
网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
返回机器人能够到达右下角的不同路径数量。
测试用例保证答案小于等于 2 * 109。
*/
/*
1.dp[row,col],到达第row行第col列的不同路径数
2.有两种方式到达下一格，所以dp[row,col] = dp[row - 1, col] + dp[row, col - 1] 
  (i, j)如果就是障碍的话应该就保持初始状态（初始状态为0）
3.dp[0,all]与dp[all, 0]均为1
4.从前向后
5.举例

O(n*m)
O(n*m)
*/
class Solution_63 {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (size_t i = 0; i < m; i++) {
      if (obstacleGrid[i][0] == 1) break;
      dp[i][0] = 1;
    }

    for (size_t i = 0; i < n; i++) {
      if (obstacleGrid[0][i] == 1) break;
      dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};