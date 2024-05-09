//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_1_H_
#define LEETCODE_INCLUDE_1_H_

/*1. 两数之和
简单
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

 提示：
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
只会存在一个有效答案
 */
#include <unordered_map>
class Solution_1 {
 public:
  //O(n^2)
  vector<int> twoSum(vector<int>& nums, int target) {
      for(int i = 0; i < nums.size(); ++i){
          for(int j = i + 1; j < nums.size(); j++){
              if(nums[i] + nums[j] == target){
                  return {i, j};
              }
          }
      }
      return {};
  }

  //O(n)
  vector<int> twoSum_map(vector<int>& nums, int target) {
      unordered_map<int, int> map;
      for(int i = 0; i < nums.size(); i++){
          int b = target - nums[i];
          auto itr = map.find(b);
          if(itr != map.end()){
              return {i, itr->second};
          } else{
              map.insert(pair<int, int>(nums[i], i));
          }
      }
      return {};
  }
};

#endif //LEETCODE_INCLUDE_1_H_
