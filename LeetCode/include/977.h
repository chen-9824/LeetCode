//
// Created by cfan on 2024/4/7.
//

#ifndef LEETCODE_INCLUDE_977_H_
#define LEETCODE_INCLUDE_977_H_

/*977. 有序数组的平方

    给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

进阶：
请你设计时间复杂度为 O(n) 的算法解决本问题
    */
#include <vector>
class Solution_977 {
 public:
  //暴力解法，时间复杂度过高
  vector<int> sortedSquares(vector<int>& nums) {
      if(nums.size() == 0)
          return nums;

      vector<int>  new_nums;
      for(auto i : nums){
          new_nums.push_back(i * i);
      }

      for(int i = 0; i < new_nums.size() - 1; ++i){
          for(int j = i + 1; j < new_nums.size(); ++j){
              if(new_nums[i] > new_nums[j]){
                  int temp = new_nums[i];
                  for(int k = i; k < j; ++k){//数组前移
                      new_nums[k] = new_nums[k + 1];
                  }
                  new_nums[j] = temp;
                  i -= 1;
                  break;
              }
          }
      }
      return new_nums;
  }

  //O(n)
  //双指针思想，借助于数组本身的非递减特性，将每个元素跟其他元素相比较优化为两两捉对比较，始终找出当前最大的元素
  vector<int> sortedSquares_double_points(vector<int>& nums) {
      vector<int>  new_nums = nums;
      int i = 0, j = nums.size() - 1, k = nums.size() - 1;
      while (k >= 0){
          if(nums[i] * nums[i] >= nums[j] * nums[j]){
              new_nums[k--] = nums[i] * nums[i];
              i += 1;
          }else{
              new_nums[k--] = nums[j] * nums[j];
              j -= 1;
          }
      }
      return new_nums;
  }
};

#endif //LEETCODE_INCLUDE_977_H_
