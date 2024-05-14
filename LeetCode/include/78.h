//
// Created by cfan on 2024/5/11.
//

#ifndef LEETCODE_INCLUDE_78_H_
#define LEETCODE_INCLUDE_78_H_
/*
 * 78. 子集
中等
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 */

class Solution_78 {
 public:
  vector<vector<int>> res;
  vector<int> path;
  void back(vector<int> &nums, int start_index) {
      res.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉过程中的子集
      if (start_index >= nums.size()) {
          return;
      }
      for (int i = start_index; i < nums.size(); i++) {
          path.push_back(nums[i]);
          back(nums, i + 1);
          path.pop_back();
      }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
      back(nums, 0);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_78_H_
