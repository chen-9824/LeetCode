//
// Created by cfan on 2024/5/13.
//

#ifndef LEETCODE_INCLUDE_47_H_
#define LEETCODE_INCLUDE_47_H_

/*
 * 47. 全排列 II
中等
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 */

class Solution_47 {
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
          if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
              continue;
          path.push_back(nums[i]);
          used[i] = 1;
          back(nums, used);
          path.pop_back();
          used[i] = 0;
      }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<int> used(nums.size(), 0);
      back(nums, used);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_47_H_
