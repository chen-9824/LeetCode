//
// Created by cfan on 2024/4/19.
//

#ifndef LEETCODE_INCLUDE_110_H_
#define LEETCODE_INCLUDE_110_H_

/*
110. 平衡二叉树
    简单
给定一个二叉树，判断它是否是平衡二叉树
一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
*/

class Solution_110 {
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
   * 返回值深度，传入节点
   * 终止条件：节点空
   * 单层递归逻辑：左子节点递归，右子节点递归，返回深度加一,如果判断出节点高度大于1，返回-1，说明不是平衡二叉树
   */
  int get_depth(TreeNode *node) {
      if (!node)
          return 0;
      int left_depth = get_depth(node->left);
      if (left_depth == -1)
          return -1;
      int right_depth = get_depth(node->right);
      if (right_depth == -1)
          return -1;
      if (abs(left_depth - right_depth) <= 1)
          return 1 + max(left_depth, right_depth);
      else
          return -1;
  }
  bool isBalanced(TreeNode *root) {
      if (!root)
          return true;
      return get_depth(root) != -1;
  }
};

#endif //LEETCODE_INCLUDE_110_H_
