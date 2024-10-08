/*
1143. 最长公共子序列
中等
提示
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。
如果不存在 公共子序列 ，返回 0 。
一个字符串的 子序列 是指这样一个新的字符串：
它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

示例 1：
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。

示例 2：
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。

示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。

提示：
1 <= text1.length, text2.length <= 1000
text1 和 text2 仅由小写英文字符组成。
*/

class Solution_1143 {
 public:
  /*
  1.dp[i][j]:
  分别以text1[i - 1]，text2[j - 1]为结尾的子字符串所共同拥有的子序列的最长长度
  2.递推公式：
  if(text1[i - 1] == text2[j - 1])
  dp[i][j] = dp[i - 1][j - 1] + 1;
  当不等时，需要取得[0~i - 1],[0 ~ j - 1]最长长度，而最长长度对应的就是dp，所以
  else
  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
  3.初始化：dp[i][0] = 0;dp[0][j] = 0;
  4.遍历顺序：从前往后，text1外循环，，text2内循环
  5.举例
  */
  int longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty()) return 0;
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i < text1.size() + 1; ++i) {
      for (int j = 1; j < text2.size() + 1; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    for (size_t i = 0; i < text1.size() + 1; i++) {
      std::cout << i << ": ";
      for (size_t j = 0; j < text2.size() + 1; j++) {
        std::cout << dp[i][j] << ", ";
      }
      std::cout << std::endl;
    }

    return dp[text1.size()][text2.size()];
  }
};