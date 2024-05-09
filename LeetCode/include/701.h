//
// Created by cfan on 2024/5/9.
//

#ifndef LEETCODE_INCLUDE_701_H_
#define LEETCODE_INCLUDE_701_H_

/*
 * 701. 二叉搜索树中的插入操作
中等
给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。
 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
 */

class Solution_701 {
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
   * 二叉搜索树本质上是有序的，中序遍历，只需找到给定值在该有序数组中的位置，因为有序，该位置必定为空节点，直接插入就行
   *
输入参数为指定节点，当前节点，返回值为新节点
终止条件为空，即找到给定值的位置
单层递归逻辑：
    判断终止条件，为真，返回新建节点
    如果给定值小于当前节点，左子节点遍历
    如果给定值大于当前节点，右子节点遍历
    返回当前节点
   */
  TreeNode *get(TreeNode *root, int val){
      //判断终止条件，为真，返回新建节点
      if(!root){
          TreeNode *node = new TreeNode(val);
          return node;
      }
      //如果给定值小于当前节点，左子节点遍历
      if(val < root->val)
          root->left = get(root->left, val);
      if(val > root->val)
          root->right = get(root->right, val);
      return root;
  }
  TreeNode *insertIntoBST(TreeNode *root, int val) {
      return get(root, val);
  }
};

#endif //LEETCODE_INCLUDE_701_H_
