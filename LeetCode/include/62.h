/*
62. 不同路径
中等
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
*/
/*
1.dp[row,col],到达第row行第col列的不同路径数
2.有两种方式到达下一格，所以dp[row,col] = dp[row - 1, col] + dp[row, col - 1]
3.dp[0,all]与dp[all, 0]均为1
4.从前向后
5.举例

O(n*m)
O(n*m)
*/
class Solution_62 {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};