//
// Created by cfan on 2024/4/3.
//

#ifndef LEETCODE__704_H_
#define LEETCODE__704_H_

/*704. 二分查找
简单

    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。*/

#include <vector>
class Solution {
 public:
  //28ms 29.23MB
  int search(vector<int> &nums, int target) {
      int n = 0;//注意初始化
      for (auto it = nums.begin(); it != nums.end(); ++it) {
          if (*it == target)
              return n;
          n += 1;
      }
      return -1;
  }
  //33ms 29.27MB
  int search_two_part(vector<int> &nums, int target) {
      int left_index = 0;
      int right_index = nums.size() - 1;
      while (left_index <= right_index) {
          int mid_index = (left_index + right_index) / 2;
          if (nums[mid_index] < target)
              left_index = mid_index + 1;
          else if (nums[mid_index] > target)
              right_index = mid_index - 1;
          else
              return mid_index;
      }
      return -1;
  }
};
#endif //LEETCODE__704_H_
