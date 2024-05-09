//
// Created by cfan on 2024/4/24.
//

#ifndef LEETCODE_INCLUDE_113_H_
#define LEETCODE_INCLUDE_113_H_

/*113. 路径总和 II
中等
    给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。*/

class Solution_113 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  /*递归函数：返回值无，输入参数为当前节点，指定值，当前路径数组，结果数组
      终止条件：当前节点为叶子节点时，判断和是否相等，如果相等结果数组添加当前路径数组
      递归逻辑：前序遍历，中左右
  1.当前路径数组加上当前节点值
  2.判断终止条件
  3.递归左右节点，注意输入参数均为引用，当前路径数组递归之后需要弹出最后一个节点，回溯到中节点，从而避免一个路径数组中记录了左右两个不可能同时到达的子节点
   */
  void get_path(TreeNode *node, int targetSum,vector<int> &cur_path, vector<vector<int>> &res){
      cur_path.push_back(node->val);
      if (!node->left && !node->right) {
          int path_sum = 0;
          for(auto i : cur_path){
              path_sum += i;
          }
          if(path_sum == targetSum){
              res.push_back(cur_path);
          }
          return;
      }
      if (node->left) {
          get_path(node->left, targetSum, cur_path, res);
          cur_path.pop_back();//回溯到中节点
      }
      if (node->right) {
          get_path(node->right, targetSum, cur_path, res);
          cur_path.pop_back();//回溯到中节点
      }
      return;
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>> res;
      if(!root)
          return res;
      vector<int> path;
      get_path(root, targetSum, path, res);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_113_H_
