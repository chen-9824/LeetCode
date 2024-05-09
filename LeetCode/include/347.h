//
// Created by cfan on 2024/4/15.
//

#ifndef LEETCODE_INCLUDE_347_H_
#define LEETCODE_INCLUDE_347_H_

/*347. 前 K 个高频元素
    中等
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]

提示：
1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。*/
#include <unordered_map>
#include <queue>
class Solution_347 {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
      vector<int> res(k);
      unordered_map<int, int> record;
      for (auto i : nums) {//统计各元素出现次数
          record[i] += 1;
      }

      //
      priority_queue<pair<int, int>, vector<pair<int, int>>, my_compare> record_queue;//优先队列

      unordered_map<int, int>::iterator itr = record.begin();
      while (itr != record.end()){//
          record_queue.push(*itr);
          if(record_queue.size() > k){//控制优先队列大小，方便得到结果
              record_queue.pop();
          }
          ++itr;
      }

      for(int i = k - 1; i >= 0; --i){//最小的优先级最高，需要反向排序
          res[i] = record_queue.top().first;
          record_queue.pop();
      }

      return res;
  }
 public:
  class my_compare{
   public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
        return lhs.second > rhs.second;//大于为真，小的优先级更高,队首元素为最小值，方便弹出当前最小，更新前k个最大元素
    }
  };
};

#endif //LEETCODE_INCLUDE_347_H_
