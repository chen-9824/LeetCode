//
// Created by cfan on 2024/4/3.
//

#ifndef LEETCODE_INCLUDE_27_H_
#define LEETCODE_INCLUDE_27_H_

/*27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素*/

class Solution_27 {
 public:
  //10ms 10.16MB
  // 时间复杂度：O(n^2)
// 空间复杂度：O(1)
  int removeElement(vector<int> &nums, int val) {
      int vec_size = nums.size();
      for (int i = 0; i < vec_size;) {
          if (nums[i] == val) {
              vec_size -= 1;//去掉该元素，数组长度减一
              for (int j = i; j < vec_size; ++j) {
                  nums[j] = nums[j + 1];//数组只能覆盖
              }
          } else
              ++i;
      }
      return vec_size;
  }
// 时间复杂度：O(n)
// 空间复杂度：O(1)
//跳过需要删除的元素
  int removeElement_double_points(vector<int> &nums, int val) {
      int fast = 0;
      int slow = 0;
      for(; fast < nums.size(); ++fast){
          if(nums[fast] != val){
              nums[slow++] = nums[fast];
          }
      }
      return slow;
  }
};
#endif //LEETCODE_INCLUDE_27_H_
