//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_104_H_
#define LEETCODE_INCLUDE_104_H_
/*104. 二叉树的最大深度
    简单
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。*/
class Solution_104 {
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
 * 迭代方法，类似层序遍历
 * 还实现了递归方法
 */
  int maxDepth(TreeNode *root) {
      int res = 0;
      if (!root)
          return res;
      queue<TreeNode *> record;
      record.push(root);
      while (!record.empty()) {
          res += 1;
          int size = record.size();
          while (size--) {
              TreeNode *node = record.front();
              record.pop();
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
          }
      }
      return res;
  }

  /*
   * 递归方法
   *
   */
  int order(TreeNode *node) {
      if(!node)
          return 0;
      int depth_1 = order(node->left);
      int depth_2 = order(node->right);
      return depth_1 > depth_2 ? (depth_1 + 1) : (depth_2 + 1);
  }
  int maxDepth_di_gui(TreeNode *root) {
      return order(root);
  }
};
#endif //LEETCODE_INCLUDE_104_H_
