//
// Created by cfan on 2024/5/11.
//

#ifndef LEETCODE_INCLUDE_39_H_
#define LEETCODE_INCLUDE_39_H_

/*
 * 39. 组合总和
中等
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
 找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 */
class Solution_39 {
 public:
  /*
   * 定义全局遍历 path， res

输入参数为指定数组，目标和target，path当前和，单层起始下标
终止条件：和大于等于target
单层回溯逻辑：
    判断终止条件
    循环取当层数组的所有元素，从单层起始下开始
    获取到的元素加入path及其和
    递归，注意，因为可以重复选取，所以单层起始下标不加一
    回溯，去掉该层循环元素

    剪枝优化
    当sum大于target时应该停止该层循环
   */
  vector<vector<int>> res;
  vector<int> path;
  void back(vector<int>& candidates, int target, int sum, int start_index){
      //判断终止条件
      if(sum == target){
          res.push_back(path);
          return;
      } else if (sum > target){
          return;
      }
      //循环取当层数组的所有元素，从单层起始下开始
      //当sum大于target时应该停止该层循环
      for(int i = start_index; i < candidates.size() && sum + candidates[i] <= target; i++){
          //获取到的元素加入path及其和
          path.push_back(candidates[i]);
          sum += candidates[i];
          //递归，注意，因为可以重复选取，所以单层起始下标不加一
          back(candidates, target, sum, i);
          //回溯，去掉该层循环元素
          path.pop_back();
          sum -= candidates[i];
      }

  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      back(candidates, target, 0, 0);
      return res;
  }
};
#endif //LEETCODE_INCLUDE_39_H_
