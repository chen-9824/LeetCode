//
// Created by cfan on 2024/5/13.
//

#ifndef LEETCODE_INCLUDE_491_H_
#define LEETCODE_INCLUDE_491_H_
/*491. 非递减子序列
    中等
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。*/

class Solution_491 {
 public:
  /*
   * 定义全局变量res, path用以保存总结果及单次结果
函数输入参数为：指定数组，起始下标，用以标记当前分支使用过的元素的数组
终止条件：起始下标超过指定数组大小，>=
单层回溯逻辑：
    保存结果，这一步是为了把遍历过程中符合条件的子集也收录进来，避免遗漏
    判断终止条件
    无序集合记录该元素在本层该分支使用，同层其他分支无法再使用该元素
    广度搜索，遍历数组所有元素
        深度搜索，基于起始下标遍历剩余的所有元素
            去重，查询无序集合中该元素是否存在，若已存在，去重
            去重，判断该子序列的最后一个值是否小于等于当前元素值，即判断加入当前元素是否仍为非递减序列
            取元素，
            递归下一个元素，
            回溯
   */
  vector<vector<int>> res;
  vector<int> path;
  void back(vector<int> &nums, int start_index) {
      if (path.size() > 1)
          res.push_back(path);
      if (start_index >= nums.size()) {
          return;
      }
      unordered_set<int> uset; // 使用set来对本层元素进行去重
      for (int i = start_index; i < nums.size(); i++) {
          if (uset.find(nums[i]) != uset.end())
              continue;
          if(!path.empty() && nums[i] < path.back())
              continue;
          path.push_back(nums[i]);
          uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
          back(nums, i + 1);
          path.pop_back();
      }
  }
  vector<vector<int>> findSubsequences(vector<int> &nums) {
      vector<int> used(nums.size(), 0);
      back(nums, 0);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_491_H_
