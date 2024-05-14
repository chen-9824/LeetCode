//
// Created by cfan on 2024/5/11.
//

#ifndef LEETCODE_INCLUDE_93_H_
#define LEETCODE_INCLUDE_93_H_

/*
 * 93. 复原 IP 地址
中等
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
 你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

 提示：
1 <= s.length <= 20
s 仅由数字组成
 */

class Solution_93 {
 public:
  /*
   * 定义全局遍历 path， res

定义全局遍历 path， res

输入参数为指定字符串，起始下标
终止条件：起始下标超过指定字符串大小，大于等于，因为起始下标从0开始
单层回溯逻辑：
    判断终止条件
    循环获取不同长度的指定字符串的子字符串，该子字符串长度<=3
    判断该子字符串第一个元素是否为0
    判断是否在[0,255]范围内
    递归
    回溯
   */
  vector<string> res;
  vector<string> path;
  void back(string s, int start_index) {
      if (start_index >= s.size()) {
          if (path.size() == 4) {

              string string1;
              for (int i = 0; i < 3; i++) {
                  string1 += path[i];
                  string1 += ".";
              }
              string1 += path[3];
              res.push_back(string1);
              return;
          }
      }
      for (int i = start_index; i < s.size() && (i - start_index + 1) <= 3; i++) {
          if (i - start_index + 1 >= 2 && s[start_index] == '0')
              continue;

          if (stoi(s.substr(start_index, i - start_index + 1)) < 0 ||
              stoi(s.substr(start_index, i - start_index + 1)) > 255)
              continue;
          path.push_back(s.substr(start_index, i - start_index + 1));
          back(s, i + 1);
          path.pop_back();
      }
  }

  vector<string> restoreIpAddresses(string s) {
      back(s, 0);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_93_H_
