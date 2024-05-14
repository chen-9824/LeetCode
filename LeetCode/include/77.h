//
// Created by cfan on 2024/5/10.
//

#ifndef LEETCODE_INCLUDE_77_H_
#define LEETCODE_INCLUDE_77_H_
/*
 * 77. 组合
中等
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
 */

class Solution_77 {
 public:
  /*
   * 回溯
回溯
输入参数为区间的元素
终止条件为单次搜索结果大小大于k
单层回溯逻辑：
    判断终止条件
    先横向遍历取一个值
    纵向遍历取一个值
    回溯()
   */

  void back(int cur, int n, int k, vector<vector<int>> &res, vector<int> &path){
      if(path.size() == k) {
          res.push_back(path);
          return;
      }
      for(int i = cur; i <= n - (k - path.size()) + 1; i++){//剪枝，当剩余元素数量不足以构成k个元素时就不用再搜索了
          path.push_back(i);
          back(i + 1, n, k, res, path);
          path.pop_back();
      }
  }

  vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> res;
      vector<int> path;
      back(1, n, k, res, path);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_77_H_
