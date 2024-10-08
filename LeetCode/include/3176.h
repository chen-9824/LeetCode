#ifndef LEETCODE_INCLUDE_3176_H
#define LEETCODE_INCLUDE_3176_H
/*
3176. 求出最长好子序列 I
中等
提示
给你一个整数数组 nums 和一个 非负 整数 k 。
如果一个整数序列 seq 满足在下标范围[0, seq.length - 2] 中
最多只有 k 个下标 i满足 seq[i] != seq[i + 1] ，
那么我们称这个整数序列为 好 序列。 请你返回 nums中好 子序列的最长长度。

示例 1：

输入：nums = [1,2,1,1,3], k = 2
输出：4
解释：
最长好子序列为 [1,2,1,1] 。

示例 2：
输入：nums = [1,2,3,4,5,1], k = 0
输出：2
解释：
最长好子序列为 [1,1] 。

提示：
1 <= nums.length <= 500
1 <= nums[i] <= 109
0 <= k <= min(nums.length, 25)
*/

class Solution_3167 {
 public:
  /*
  1.dp[i][j]:以nums[0~i-1]区间为结尾的最多dp[j]个相邻不等元素，好
  子序列的最长长度 2.递推公式：三种情况 2.1 nums[i] == nums[i - 1], dp[i] = dp[i
  - 1] + 1 2.2 nums[i] != nums[i - 1] && dp[i - 1][j - 1] < k, dp[i] = dp[i - 1]
  + 1; k_num += 1; 2.3 nums[i] != nums[i - 1] && k_num >= k, dp[i] = dp[i - 1]
  3.初始化：dp[i] = 2;
  4.遍历顺序：从前向后
  5.举例
  */
  int maximumLength(vector<int>& nums, int k) {
    int res = 0;
    if (nums.size() <= 2) return res;
    for (int i = 0; i < nums.size(); i++) {
      vector<int> temp;
      int n = 0;
      temp.push_back(nums[i]);
      for (int j = i + 1; j < nums.size(); j++) {
        temp.push_back(nums[j]);

        if (temp.at(temp.size() - 1) != nums[j]) {
          if (n == k) {
            res = res > n ? res : n;
          }
        }
      }
    }
  }
};

#endif  // LEETCODE_INCLUDE_3176_H