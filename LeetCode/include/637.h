//
// Created by cfan on 2024/4/17.
//

#ifndef LEETCODE_INCLUDE_637_H_
#define LEETCODE_INCLUDE_637_H_
/*637. 二叉树的层平均值
    简单

给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5 以内的答案可以被接受。*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution_637 {
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
 * 本题就是102 层序遍历的时候把一层求个总和在取一个均值。
 */
  vector<double> averageOfLevels(TreeNode *root) {
      vector<double> res;
      if (!root)
          return res;
      queue<TreeNode *> record;
      record.push(root);
      while (!record.empty()) {
          int size = record.size();
          double sum = 0;
          for(int i = 0; i < size; ++i) {
              TreeNode *node = record.front();
              sum += (node->val);
              record.pop();
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
          }
          res.push_back(sum / size);
      }
      return res;
  }
};
#endif //LEETCODE_INCLUDE_637_H_
