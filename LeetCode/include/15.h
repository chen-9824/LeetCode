//
// Created by cfan on 2024/4/9.
//

#ifndef LEETCODE_INCLUDE_15_H_
#define LEETCODE_INCLUDE_15_H_


/*
 * 15. 三数之和
    中等
提示
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    同时还满足 nums[i] + nums[j] + nums[k] == 0 。
    请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
 */
#include <algorithm>
class Solution_15 {
 public:
  /*
   * 暴力解法可以找到三元组，但是不知道怎么去重
   *
   *关键是三元组内部可重复，但是多个三元组的元素不能重复，所以应该对三个元素进行去重操作
   * 对第一个元素的去重重点在于由后一个元素判断前一个元素是否相同，如果对前一个元素进行去重，会使得类似{-1, -1, 2}这样的三元组被去掉
   * 对双指针指向的两个元素去重关键是得在拿到第一个符合条件的三元组之后进行去重，负责类似于{0, 0, 0}这样的三元组会被去掉
   */

  //去重失败
  vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      for(int i = 0; i < nums.size(); ++i){
          if(nums[i] > 0)
              return res;
          if(i > 0){
              nums[i] = nums[i - 1];
              continue;
          }
          for(int j = i + 1; j < nums.size(); ++j){
              if(j > 0){
                  nums[j] = nums[j - 1];
                  continue;
              }
              for(int k = j + 1; k < nums.size(); ++k){
                  if(k > 0){
                      nums[k] = nums[k - 1];
                      continue;
                  }
                  if(nums[i] + nums[j] + nums[k] == 0)
                      res.push_back(vector<int>{nums[i], nums[j], nums[k]});
              }
          }
      }
      return res;
  }

  vector<vector<int>> threeSum_double_points(vector<int> &nums) {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] > 0)
              return res;
          if (i > 0) {//去重,跟前一个比较，避免类似{-1, -1, 2}这样的三元组被去掉
              if (nums[i] == nums[i - 1])
                  continue;
          }
          int left = i + 1;
          int right = nums.size() - 1;
          while (left < right) {
              if (nums[i] + nums[left] + nums[right] == 0) {
                  res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                  while (left < right && nums[left] == nums[left + 1])//去重
                      left += 1;
                  while (left < right && nums[right] == nums[right - 1])//去重
                      right -= 1;

                  left += 1;
                  right -= 1;
              } else if (nums[i] + nums[left] + nums[right] < 0) {
                  left += 1;
              } else {
                  right -= 1;
              }
          }
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_15_H_
