//
// Created by cfan on 2024/5/10.
//

#ifndef LEETCODE_INCLUDE_17_H_
#define LEETCODE_INCLUDE_17_H_

/*
 * 17. 电话号码的字母组合
中等
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */

const string letter_map[] = {
    "", "", "abc",
    "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};
vector<string> res;
string path;
void back(string digits, int cur){
    if(path.size() == digits.size()){
        res.push_back(path);
        return;
    }

    //for(auto i = cur; i < digits.size(); i++){
        int n = digits[cur] - '0';
        for(auto j : letter_map[n]){
            path.push_back(j);
            back(digits, cur + 1);
            path.pop_back();
        }
    //}
}
class Solution_17 {
 public:
  vector<string> letterCombinations(string digits) {
      if(digits.empty())
          return res;
      back(digits, 0);
      return res;
  }
};
#endif //LEETCODE_INCLUDE_17_H_
