//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_349_H_
#define LEETCODE_INCLUDE_349_H_
/*349. 两个数组的交集
简单
    给定两个数组 nums1 和 nums2 ，返回 它们的交集。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

    提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
    */

class Solution_349 {
 public:
  //O(m+n)
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      vector<int> record(1000, 0);
      vector<int> res;
      for(auto i : nums1)
          record[i] += 1;
      for(auto i : nums2) {
          if(record[i] != 0){
              record[i] = -1;//去重
          }
      }
      for(int i = 0; i < record.size(); i++){
          if(record[i] == -1){
              res.push_back(i);
          }
      }
      return res;
  }
};
#endif //LEETCODE_INCLUDE_349_H_
