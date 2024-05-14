//
// Created by cfan on 2024/5/11.
//

#ifndef LEETCODE_INCLUDE_131_H_
#define LEETCODE_INCLUDE_131_H_
/*
 * 131. 分割回文串
中等
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。返回 s 所有可能的分割方案。
 */

class Solution_131 {
 public:
  /*
   * 输入参数为指定字符串，起始下标
终止条件：起始下标超过指定字符串大小，大于等于，因为起始下标从0开始
单层回溯逻辑：
    判断终止条件
    第一层循环用于不停增加子字符串的长度，遍历所有不同长度的子字符串
     判断该字符串是否为回文，双指针
     获取子字符串s[start_index, i]，
     递归其余子字符串
     回溯
   */
  vector<vector<string>> res;
  vector<string> path;
  bool is_str(string &s, int start_index, int end){
      int i = start_index;
      int j = end;
      while (i < j){
          if(s[i] != s[j])
              return false;
          i += 1;
          j -= 1;
      }
      return true;
  }
  void back(string &s, int start_index){
      //判断终止条件
      if(start_index >= s.size()){
          res.push_back(path);
      }
      //第一层循环用于不停增加子字符串的长度，遍历所有不同长度的子字符串
      for(int i = start_index; i < s.size(); i++){
          //判断该字符串是否为回文，双指针
          if(is_str(s, start_index, i)){
              //获取子字符串s[start_index, i]，
              path.push_back(s.substr(start_index, i - start_index + 1));
              //递归其余子字符串
              back(s, i + 1);
              //回溯
              path.pop_back();
          } else
              continue;
      }
  }
  vector<vector<string>> partition(string s) {
      back(s, 0);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_131_H_
