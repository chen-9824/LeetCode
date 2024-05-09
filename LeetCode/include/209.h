//
// Created by cfan on 2024/4/7.
//

#ifndef LEETCODE_INCLUDE_209_H_
#define LEETCODE_INCLUDE_209_H_

/*209. 长度最小的子数组

中等

给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组
[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。*/

class Solution_209 {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
      int res_start = 0, res_end = 0;
      int sum = 0;
      int res = INT32_MAX;
      while (res_end < nums.size()){
          sum += nums[res_end];
          while(sum >= target){
              int length = res_end - res_start + 1;
              res = res < length ? res : length;
              sum -= nums[res_start++];
          }
          res_end += 1;
      }
      return res == INT32_MAX ? 0 : res;
  }
};

#endif //LEETCODE_INCLUDE_209_H_
