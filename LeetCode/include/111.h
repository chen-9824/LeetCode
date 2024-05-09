//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_111_H_
#define LEETCODE_INCLUDE_111_H_
/*111. 二叉树的最小深度
    简单
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。*/
class Solution_111 {
 public:
  struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  int minDepth(TreeNode* root) {
      int res = 0;
      if(!root)
          return res;
      queue<TreeNode*> record;
      record.push(root);
      while (!record.empty()){
          res += 1;
          int size = record.size();
          while (size--) {
              TreeNode *node = record.front();
              record.pop();
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
              if(!node->left && !node->right)
                  return res;
          }
      }
      return res;
  }

  /*
   * 返回参数为左右子树最小深度，输入参数为节点
终止条件为节点为空
单层递归逻辑为单个节点为空时最小深度为1+另一节点深度
否则为1+两者最小节点深度
   */
  int get_depth(TreeNode* node){
      if(!node)
          return 0;
      int left_depth = get_depth(node->left);
      int right_depth = get_depth(node->right);
      if(!node->left && node->right)
          return 1 + right_depth;
      if(!node->right && node->left)
          return 1 + left_depth;
      return 1 + min(left_depth, right_depth);
  }
  int minDepth_di_gui(TreeNode* root) {
      return get_depth(root);
  }
};
#endif //LEETCODE_INCLUDE_111_H_
