//
// Created by cfan on 2024/4/24.
//

#ifndef LEETCODE_INCLUDE_112_H_
#define LEETCODE_INCLUDE_112_H_
/*112. 路径总和
简单
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum .
 判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
 如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。*/



class Solution_112 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  /*递归函数：返回值为根节点到叶子节点的高度是否等于指定值，输入参数为当前节点，指定值，路径和
终止条件：当前节点为叶子节点时，判断和是否相等，返回结果
递归逻辑：
前序遍历，中左右
1.和加上当前节点值
2.判断终止条件
3.递归左右节点*/
  bool getPathSum(TreeNode *node, int targetSum, int path_sum) {
      path_sum += node->val;
      if (!node->left && !node->right) {
          return path_sum == targetSum;
      }
      bool left_res{false};
      bool right_res{false};
      if (node->left)
          left_res = getPathSum(node->left, targetSum, path_sum);
      if (node->right)
          right_res = getPathSum(node->right, targetSum, path_sum);
      return (left_res | right_res);
  }

  bool hasPathSum(TreeNode *root, int targetSum) {

      if(!root)
          return false;
      int sum = 0;
      return getPathSum(root, targetSum, sum);
  }
};

#endif //LEETCODE_INCLUDE_112_H_
