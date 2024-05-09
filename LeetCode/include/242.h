//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_242_H_
#define LEETCODE_INCLUDE_242_H_

/*242. 有效的字母异位词
简单
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。*/

class Solution_242 {
 public:
  //O(n^2)
  bool isAnagram(string s, string t) {
      if(s.size() != t.size())
          return false;
      for(int i = 0; i < s.size(); i++){
          auto pos = t.find(s[i]);
          if(pos != string::npos){
              t.erase(pos, 1);
          } else{
              return false;
          }
      }
      return true;
  }

  //O(n)
  bool isAnagram_hash(string s, string t) {
      int record[26] = {0};
      for(int i = 0; i < s.size(); i++){
          record[s[i] - 'a'] += 1;
      }
      for(int i = 0; i < t.size(); i++){
          record[t[i] - 'a'] -= 1;
      }
      for(int i = 0; i < 26; i++){
          if(record[i] != 0)
              return false;
      }
      return true;
  }
};
#endif //LEETCODE_INCLUDE_242_H_
