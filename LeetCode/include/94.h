//
// Created by cfan on 2024/4/16.
//

#ifndef LEETCODE_INCLUDE_94_H_
#define LEETCODE_INCLUDE_94_H_
/*94. 二叉树的中序遍历
简单
    给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution_94 {
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 public:
  void traversal(TreeNode *node, vector<int> &vec) {
      if (node == nullptr)
          return;

      traversal(node->left, vec);
      vec.push_back(node->val);
      traversal(node->right, vec);
  }
  vector<int> inorderTraversal(TreeNode *root) {
      vector<int> res;
      traversal(root, res);
      return res;
  }

  vector<int> inorderTraversal_stack(TreeNode *root) {
      stack<TreeNode *> traversal;
      vector<int> res;
      if (!root)
          return res;
      TreeNode *cur = root;
      //traversal.push(root);//需要先遍历出左子节点再入栈处理
      while (cur != nullptr || !traversal.empty() ) {
          if (cur != nullptr) {//遍历所有左节点
              traversal.push(cur);
              cur = cur->left;
          } else {//按中序访问元素
              cur = traversal.top();
              traversal.pop();
              res.push_back(cur->val);
              cur = cur->right;
          }
      }
      return res;
  }
};
#endif //LEETCODE_INCLUDE_94_H_
