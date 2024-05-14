//
// Created by cfan on 2024/5/13.
//

#ifndef LEETCODE_INCLUDE_46_H_
#define LEETCODE_INCLUDE_46_H_

/*
 * 46. 全排列
中等
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
 */

class Solution_46 {
 public:
  vector<vector<int>> res;
  vector<int> path;
  void back(vector<int>& nums, vector<int>& used){
      if(path.size() >= nums.size()){
          res.push_back(path);
          return;
      }
      for(int i = 0; i < nums.size(); i++){
          if(used[i] == 1)
              continue;
          path.push_back(nums[i]);
          used[i] = 1;
          back(nums, used);
          path.pop_back();
          used[i] = 0;
      }
  }
  vector<vector<int>> permute(vector<int>& nums) {
      vector<int> used(nums.size(), 0);
      back(nums, used);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_46_H_
