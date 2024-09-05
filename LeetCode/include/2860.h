//
// Created by cfan on 2024/9/5.
//

#ifndef LEETCODE_INCLUDE_2860_H_
#define LEETCODE_INCLUDE_2860_H_
/*
 * 2860. 让所有学生保持开心的分组方法数
中等
提示
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，其中 n 是班级中学生的总数。班主任希望能够在让所有学生保持开心的情况下选出一组学生：
如果能够满足下述两个条件之一，则认为第 i 位学生将会保持开心：
    这位学生被选中，并且被选中的学生人数 严格大于 nums[i] 。
    这位学生没有被选中，并且被选中的学生人数 严格小于 nums[i] 。
返回能够满足让所有学生保持开心的分组方法的数目。

 1 <= nums.length <= 105
0 <= nums[i] < nums.length
 */

class Solution_2860 {
 public:
  /*
   * 使用回溯先分组再判断快乐方法可行，但是耗时太久了
   * 根据题意条件使用排序方式，因为取k个学生的分组方法是一定的，
  */
  void groupedByNum(const vector<int>& nums, unordered_map<int, int>& temp, int& res, int num, int currentIndex){
      if(temp.size() >= num){
          int k = 0;
          //std::cout << "group " << res << ": ";
          for(int i = 0; i < nums.size(); ++i){
              //std::cout << nums[i] << ", ";
              if(temp.find(i) != temp.end()){//选中学生
                  if(num <= nums[i]) {
                      k = 1;
                      break;
                  }
              }
              else{
                  if(num >= nums[i]) {
                      k = 1;
                      break;
                  }
              }
          }
          //std::cout << std::endl;

          if(k == 0) {
              res += 1;
              auto it = temp.cbegin();
              std::cout << "group " << res << ": ";
              while (it != temp.cend()){
                  std::cout << it->first << ", ";
                  ++it;
              }
              std::cout << std::endl;
          }
          return;
      }

      for(int i = currentIndex; i < nums.size(); i++){
          temp.insert({i, nums[i]});
          groupedByNum(nums, temp, res, num, i + 1);
          temp.erase(i);
      }
  }

  int countWays(vector<int>& nums) {
      int resNum = 0;
      if(nums.empty())
          return resNum;

      for(int i = 0; i <= nums.size(); i++){
          unordered_map<int, int> temp;
          groupedByNum(nums, temp, resNum, i, 0);
      }
      return resNum;
  }

  int countWays_sort(vector<int>& nums) {
      int res = 0;
      if(nums.empty()){
          return res;
      }

      sort(nums.begin(), nums.end());
      //[0]
      if(nums[0] > 0)
          res += 1;
      //(0, n)
      for(int i = 1; i < nums.size(); i++){
          if(nums[i - 1] < i && nums[i] > i)
              res += 1;
      }
      //[n]
      if(nums[nums.size() - 1] < nums.size())
          res += 1;
      return res;
  }

};
#endif //LEETCODE_INCLUDE_2860_H_
