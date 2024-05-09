//
// Created by cfan on 2024/4/9.
//

#ifndef LEETCODE_INCLUDE_454_H_
#define LEETCODE_INCLUDE_454_H_

/*454. 四数相加 II
中等

给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 */

#include <unordered_map>

class Solution_454 {
 public:
  /*
   * 暴力解法四层for循环，显然时间复杂度很高
   * 给出等式，可以根据等式遍历部分数组然后匹配查找需要的另外部分数组元素，即查找某个元素在集合中是否出现过，可以用哈希表，并且不用去重。
   * 因为四个独立数组，即使用哈希表也需要遍历求和，只是可以分开求，所以最好是两两分组，最多是两层for循环
   * 那思路就是用map保存两个数组之和及其出现次数，再遍历另外两个数组和，在map查询满足等式的元素是否存在，出现了多少次，从而得到结果
   * 使用无序map,底层实现是哈希，搜索效率高
   * O(n^2)
   */
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      unordered_map<int, int> record_map;
      for(auto a : nums1){//map保存两个数组之和及其出现次数
          for(auto b : nums2)
              ++record_map[a + b];
      }
      int count = 0;
      for(auto c : nums3){
          for(auto d : nums4){
              auto itr = record_map.find((0 - (c + d)));
              if(itr != record_map.end())
                  count += itr->second;
          }
      }
      return count;
  }
};

#endif //LEETCODE_INCLUDE_454_H_
