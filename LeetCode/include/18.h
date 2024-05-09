//
// Created by cfan on 2024/4/10.
//

#ifndef LEETCODE_INCLUDE_18_H_
#define LEETCODE_INCLUDE_18_H_

/*18. 四数之和
    中等
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
 请你找出并返回满足下述全部条件且不重复的四元组[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
    你可以按 任意顺序 返回答案 。*/

class Solution_18 {
 public:
  /*
   * 跟15相同的解法
   */
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); ++i) {
          if(nums[i] > target)
              return res;
          if(i > 0 && nums[i] == nums[i - 1])
              continue;
          for (int j = i + 1; j < nums.size(); ++j) {

              if(j > 1 && nums[j] == nums[j - 1])
                  continue;

              int left = j + 1;
              int right = nums.size() - 1;
              while (left < right) {
                  if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                      left += 1;
                  else if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                      right -= 1;
                  else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                      while (left < right && nums[left] == nums[left + 1])
                          left += 1;
                      while (left < right && nums[right] == nums[right - 1])
                          right -= 1;

                      left += 1;
                      right -= 1;
                  }
              }
          }
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_18_H_