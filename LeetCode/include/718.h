/*
718. 最长重复子数组
中等
提示
给两个整数数组 nums1 和 nums2 ，
返回 两个数组中 公共的、长度最长的子数组的长度。

示例 1：
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。

示例 2：
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5

提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

class Solution_718 {
 public:
  /*
  1.dp[i][j]:以nums1[i - 1]及nums2[j - 1]为结尾的重复子数组的最长长度
  2.递推条件：if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
  3.初始化：d[i][0] = 0;d[0][j] = 0;
  因为递推公式从i-1开始，i，j不能为0，即dp[i][0]及dp[0][j]均无意义
  方便处理[0],[0]这种开始就重复的情况
  4.遍历顺序：均为从前向后，nums1做外层循环，nums2做内层循环
  5.举例
  */
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) return 0;
    int res = 0;
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    for (int i = 1; i < nums1.size() + 1; ++i) {
      for (int j = 1; j < nums2.size() + 1; ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          res = res > dp[i][j] ? res : dp[i][j];
        }
      }
    }

    for (size_t i = 0; i < nums1.size() + 1; i++) {
      std::cout << i << ": ";
      for (size_t j = 0; j < nums2.size() + 1; j++) {
        std::cout << dp[i][j] << ", ";
      }
      std::cout << std::endl;
    }

    return res;
  }
};