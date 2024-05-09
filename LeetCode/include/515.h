//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_515_H_
#define LEETCODE_INCLUDE_515_H_

/*
515. 在每个树行中找最大值
    中等
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
*/

class Solution_515 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



  vector<int> largestValues(TreeNode *root) {
      vector<int> res;
      if (!root)
          return res;
      queue<TreeNode *> record;
      record.push(root);
      while (!record.empty()) {
          int size = record.size();
          int max_num = record.front()->val;
          for (int i = 0; i < size; i++) {
              TreeNode *node = record.front();
              if (max_num < node->val)
                  max_num = (node->val);
              record.pop();
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
          }
          res.push_back(max_num);
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_515_H_
