//
// Created by cfan on 2024/5/11.
//

#ifndef LEETCODE_INCLUDE_40_H_
#define LEETCODE_INCLUDE_40_H_

/*
 * 40. 组合总和 II
中等
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。
 提示:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
 */

class Solution_40 {
 public:
  /*
 * 定义全局遍历 path， res

输入参数为指定数组，目标和target，path当前和，单层起始下标
终止条件：和大于等于target
单层回溯逻辑：
  判断终止条件
  循环取当层数组的所有元素，从单层起始下开始
  获取到的元素加入path及其和
  递归，每个数字在每个组合中只能使用 一次
  回溯，去掉该层循环元素

  剪枝优化
  当sum大于target时应该停止该层循环
 */
  vector<vector<int>> res;
  vector<int> path;

  void back(vector<int> &candidates, int target, int sum, int start_index, vector<int> &used) {
      //判断终止条件
      if (sum == target) {
          res.push_back(path);
          return;
      } else if (sum > target) {
          return;
      }
      //循环取当层数组的所有元素，从单层起始下开始
      //当sum大于target时应该停止该层循环
      for (int i = start_index; i < candidates.size() && sum + candidates[i] <= target; i++) {
          if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0) {
              continue;
          }
          //获取到的元素加入path及其和
          path.push_back(candidates[i]);
          sum += candidates[i];
          used[i] = 1;
          //递归，每个数字在每个组合中只能使用 一次
          back(candidates, target, sum, i + 1, used);
          //回溯，去掉该层循环元素
          path.pop_back();
          sum -= candidates[i];
          used[i] = 0;
      }

  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
      vector<int> used(candidates.size(), 0);
      // 首先把给candidates排序，让其相同的元素都挨在一起。
      sort(candidates.begin(), candidates.end());
      back(candidates, target, 0, 0, used);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_40_H_
