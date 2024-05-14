//
// Created by cfan on 2024/5/10.
//

#ifndef LEETCODE_INCLUDE_669_H_
#define LEETCODE_INCLUDE_669_H_
/*
 * 669. 修剪二叉搜索树
中等
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
 修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
 */

class Solution_669 {
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
   * 修剪指定区间，按中序遍历，很容易把区间内的右孩子节点剪掉，所以在剪掉中间节点时，将右孩子节点挂到上一节点的左孩子节点
输入参数为当前节点，返回值为修剪后的节点
终止条件为当前节点是否为空
单层递归逻辑：
    判断终止条件，为真返回空
    若当前节点值大于high，遍历左子节点，返回得到的结果
    若当前节点值小于low，遍历右子节点，返回得到的结果
    处理当前节点的下一层节点，以便接住下层向上返回的节点
    返回当前节点
   */
  TreeNode *get(TreeNode *root, int low, int high){
      if(!root)
          return nullptr;

      if(root->val < low) {
          TreeNode *right = get(root->right, low, high);
          return right;
      }
      else if(root->val > high) {
          TreeNode *left = get(root->left, low, high);
          return left;
      }

      //处理当前节点的下一层节点，以便接住下层向上返回的节点
      root->left = get(root->left, low, high);
      root->right = get(root->right, low, high);

      return root;
  }

  TreeNode *trimBST(TreeNode *root, int low, int high) {
      return get(root, low, high);
  }
};
#endif //LEETCODE_INCLUDE_669_H_
