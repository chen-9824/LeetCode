//
// Created by cfan on 2024/5/8.
//

#ifndef LEETCODE_INCLUDE_98_H_
#define LEETCODE_INCLUDE_98_H_

/*
 * 98. 验证二叉搜索树
中等
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 */
class Solution_98 {
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
   * 输入参数为当前节点，返回值为是否为有效二叉搜索树
终止条件为当前节点为空
单层递归逻辑：
判断终止条件，返回真
遍历左子树

判断当前节点值是否大于等于上一个节点值，即是否是递增的
若为真，返回假

遍历右子树
返回真

   注意：应该是左子树所有节点小于中间节点，而不是左子节点小于中间节点
   */
  TreeNode* pre;
  bool get(TreeNode* node){
      //判断终止条件，返回真
      if(!node)
          return true;
      //遍历左子树
      bool left = get(node->left);
      //判断当前节点值是否大于等于上一个节点值，即是否是递增的
      if(pre && pre->val >= node->val)
          return false;
      pre = node;

      //遍历右子树
      bool right = get(node->right);

      return (left && right);
  }

  bool isValidBST(TreeNode* root) {
      return get(root);
  }
};
#endif //LEETCODE_INCLUDE_98_H_
