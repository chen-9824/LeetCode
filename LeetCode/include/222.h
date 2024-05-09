//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_222_H_
#define LEETCODE_INCLUDE_222_H_
/*222. 完全二叉树的节点个数
    简单
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。*/
class Solution_222 {
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
   * 迭代法，102 层序遍历
   * 递归法
   */
  int countNodes(TreeNode* root) {
      int res = 0;
      if(!root)
          return res;
      queue<TreeNode*> record;
      record.push(root);
      while (!record.empty()){
          int size = record.size();
          res += size;
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
   * 递归法
   */
  int get_node_num(TreeNode* node){
      if(!node)
          return 0;
      int left = get_node_num(node->left);
      int right = get_node_num(node->right);
      return 1 + left + right;
  }

  int countNodes_di_gui(TreeNode* root) {
      return get_node_num(root);
  }
};
#endif //LEETCODE_INCLUDE_222_H_
