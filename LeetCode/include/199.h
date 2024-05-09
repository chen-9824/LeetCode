//
// Created by cfan on 2024/4/17.
//

#ifndef LEETCODE_INCLUDE_199_H_
#define LEETCODE_INCLUDE_199_H_
/*199. 二叉树的右视图
    中等
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。*/

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
class Solution_199 {
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
 * 102 层序遍历的思路，只需要跳过该层前面的值拿最后一个就可以
 */
  vector<int> rightSideView(TreeNode *root) {
      vector<int> res;
      if(!root)
          return res;
      queue<TreeNode *> record;
      record.push(root);
      while (!record.empty()){
          int size = record.size();
          TreeNode *node;
          while (size--) {
              node = record.front();
              record.pop();
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
          }
          res.push_back(node->val);
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_199_H_
