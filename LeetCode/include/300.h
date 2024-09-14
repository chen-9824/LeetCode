/*
300. 最长递增子序列
中等
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列
是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

class Solution_300 {
 public:
  /*
  1.dp[i]: 从i之前的以nums[i]为结尾的严格递增子序列的最大长度
  2.递推公式：当nums[i] > nums[j]时，dp[i]为j在[0, i
  -1]区间严格递增子序列的最大长度加一（加上dp[i]） 即if(nums[i] > nums[j]) dp[i]
  = max(dp[i], dp[j] + 1) 3.dp初始化：显然初始值即初始长度均为1
  4.遍历顺序：i，j均为从前向后
  5.举例
  */
  int lengthOfLIS(vector<int>& nums) {
    int res = 1;
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
      }
      res = res > dp[i] ? res : dp[i];
    }

    std::cout << "res: ";
    for (auto i : dp) {
      std::cout << i << ", ";
    }
    std::cout << std::endl;

    return res;
  }
};