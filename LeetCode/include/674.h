/*
674. 最长连续递增序列
简单
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i <
r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r -
1], nums[r]] 就是连续递增子序列。
*/

class Solution_674 {
 public:
  /*
  类似于300，关键在于子序列是否连续
  1.dp[i]:以nums[i]为结尾的最长连续递增子序列的长度
  2.递推公式：因为需求连续，所以当nums[i] > nums[j]时，nums[i] = nums[j] + 1,
    不需要考虑[0, i - 1)整个范围的最大长度, j = i - 1;
  3.dp[i]初始化：最大长度至少为1
  4.遍历顺序：从前往后
  5.举例打印验证
  */
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();

    int res = 0;
    vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;

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