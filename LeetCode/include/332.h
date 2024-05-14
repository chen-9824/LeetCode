//
// Created by cfan on 2024/5/14.
//

#ifndef LEETCODE_INCLUDE_332_H_
#define LEETCODE_INCLUDE_332_H_

/*
 * 332. 重新安排行程
困难
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

 */
#include <unordered_map>
#include <map>
class Solution_332 {
 public:
  unordered_map<string, map<string, int>> res;
  bool back(int tickt_num, vector<string>& path){
      if(tickt_num + 1 == path.size()){
          return true;
      }

      for(auto &arrive : res[path[path.size() - 1]]){
          if(arrive.second > 0){
              path.push_back(arrive.first);
              arrive.second -= 1;
              if(back(tickt_num, path))
                  return true;
              path.pop_back();
              arrive.second += 1;
          }
      }
      return false;
  }
  vector<string> findItinerary(vector<vector<string>>& tickets) {

      for(vector<string> start : tickets){
          res[start[0]][start[1]]++;
      }
      vector<string> path;
      path.push_back("JFK");
      back(tickets.size(), path);
      return path;
  }
};

#endif //LEETCODE_INCLUDE_332_H_
