//
// Created by cfan on 2024/4/9.
//

#ifndef LEETCODE_INCLUDE_383_H_
#define LEETCODE_INCLUDE_383_H_

/*
383. 赎金信
    简单
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。
*/
#include <unordered_set>
class Solution_383 {
 public:
  /*
   *查找某个元素在集合中是否出现过，可以用哈希表
   * O(n),但是因为涉及到删除操作，复杂度更高
   */
  bool canConstruct(string ransomNote, string magazine) {
      unordered_multiset<char> magazine_set(magazine.cbegin(), magazine.cend());
      for(auto i : ransomNote){
          auto itr = magazine_set.find(i);
          if(itr != magazine_set.end()){
              magazine_set.erase(itr);
          } else
              return false;
      }
      return true;
  }

  /*
   * 类似于242，可以用数组来保存元素及其出现次数，更快,
   * 还是哈希表思想
   * O(n),但是没有删除操作
   */
  bool canConstruct_hash(string ransomNote, string magazine) {
      int record[26] = {0};
      for(auto i : magazine){
          record[i - 'a'] += 1;
      }
      for(auto i : ransomNote){
          if(record[i - 'a'] > 0){
              record[i - 'a'] -= 1;
          } else
              return false;
      }
      return true;
  }
};

#endif //LEETCODE_INCLUDE_383_H_
