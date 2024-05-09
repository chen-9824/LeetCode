//
// Created by cfan on 2024/5/9.
//

#ifndef LEETCODE_INCLUDE_530_H_
#define LEETCODE_INCLUDE_530_H_

#include <climits>
/*
 * 530. 二叉搜索树的最小绝对差
简单
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。
 提示：
树中节点的数目范围是 [2, 104]
0 <= Node.val <= 105
 */

class Solution_530 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  /*
   * 中序遍历，方便利用有序特性,定义一个前指针，与当前节点比较
输入参数为当前节点，无输出
终止条件为输入节点为空
单层递归逻辑：
判断终止条件
遍历左节点
遍历中节点，计算当前节点与前一个节点差值，更新前一个节点
遍历右节点
   */
  TreeNode* per = nullptr;
  int res = INT_MAX;
  void get(TreeNode* node){
      //判断终止条件
      if(!node)
          return;
      //遍历左节点
      get(node->left);
      //遍历中节点，计算当前节点与前一个节点差值，更新前一个节点
      if(per){
          int temp = abs(node->val - per->val);
          res = min(temp, res);
      }
      per = node;
      //遍历右节点
      get(node->right);
      return;
  }

  int getMinimumDifference(TreeNode* root) {
      get(root);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_530_H_
