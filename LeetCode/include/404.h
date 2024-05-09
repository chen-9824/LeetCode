//
// Created by cfan on 2024/4/19.
//

#ifndef LEETCODE_INCLUDE_404_H_
#define LEETCODE_INCLUDE_404_H_
/*404. 左叶子之和
    简单
给定二叉树的根节点 root ，返回所有左叶子之和。*/
class Solution_404 {
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
   * 无返回参数，输入当前节点，当前节点是否为左子树，和
终止条件：当前节点为叶子节点，判断是否为左子树，和加当前节点值
单层递归逻辑：
判断是否终止
左子节点递归，
右子节点递归
   */
  void get_sum(TreeNode* node, bool is_left, int &sum){
      if(!node->left && !node->right){
          if(is_left)
              sum += node->val;
          return;
      }
      if(node->left)
          get_sum(node->left, true, sum);
      if(node->right)
          get_sum(node->right, false, sum);
  }
  int sumOfLeftLeaves(TreeNode* root) {
      int sum = 0;
      if(!root)
          return sum;
      get_sum(root, false, sum);
      return sum;
  }
};
#endif //LEETCODE_INCLUDE_404_H_
