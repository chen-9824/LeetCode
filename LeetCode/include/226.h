//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_226_H_
#define LEETCODE_INCLUDE_226_H_

/*226. 翻转二叉树
    简单
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。*/

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
class Solution_226 {
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
   * 102 层序遍历类似
   * 还有其他方法，广度优先搜索，但是中序不方便，
   * 递归也可以
   */
  TreeNode *invertTree(TreeNode *root) {
      if(!root)
          return root;
      queue<TreeNode *> record;
      record.push(root);
      while (!record.empty()) {
          int size = record.size();
          while (size--) {
              TreeNode *node = record.front();
              record.pop();
              TreeNode *temp = node->left;
              node->left = node->right;
              node->right = temp;
              if(node->left)
                  record.push(node->left);
              if(node->right)
                  record.push(node->right);
          }
      }
      return root;
  }
};

#endif //LEETCODE_INCLUDE_226_H_
