//
// Created by cfan on 2024/5/11.
//

#ifndef LEETCODE_INCLUDE_90_H_
#define LEETCODE_INCLUDE_90_H_
/*
 * 90. 子集 II
中等
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 */
class Solution_90 {
 public:
  vector<vector<int>> res;
  vector<int> path;

  void back(vector<int>& nums, int start_index, vector<int> &used){
      res.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉过程中的子集
      if (start_index >= nums.size()) {
          return;
      }
      for(int i = start_index; i < nums.size(); i++){
          if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
              continue;
          path.push_back(nums[i]);
          used[i] = 1;
          back(nums, i + 1, used);
          path.pop_back();
          used[i] = 0;
      }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> used(nums.size(), 0);
      sort(nums.begin(), nums.end());
      back(nums, 0, used);
      return res;
  }
};
#endif //LEETCODE_INCLUDE_90_H_
