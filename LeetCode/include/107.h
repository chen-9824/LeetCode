//
// Created by cfan on 2024/4/17.
//

#ifndef LEETCODE_INCLUDE_107_H_
#define LEETCODE_INCLUDE_107_H_

/*
 * 107. 二叉树的层序遍历 II
中等
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 */

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
class Solution_107 {
 public:
  struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  /*
   * 102 层序遍历反转下结果就行
   * 两种方法，队列，递归
   */
  void order(int depth, TreeNode* node, vector<vector<int>> &vec){
      if(!node)
          return;
      if(depth >= vec.size())//多维数组需要初始化
          vec.push_back(vector<int>());
      vec[depth].push_back(node->val);
      if(node->left)
          order(depth + 1, node->left, vec);
      if(node->right)
          order(depth + 1, node->right, vec);
  }
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> res;
      int depth = 0;
      order(depth, root, res);
      auto itr_b = res.begin();
      auto itr_e = res.end();
      //reverse(itr_b, itr_e);
      while (itr_b != itr_e && itr_b != --itr_e){//首先--itr_e保证尾迭代器不指向空,其次保证不会有指向同一个元素时因为--，++而错过导致无限迭代
          swap(*itr_b, *itr_e);//解引用，否则交换的是两个指针的内容，而不是指针指向的内容
          ++itr_b;
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_107_H_
