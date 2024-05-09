//
// Created by cfan on 2024/4/16.
//

#ifndef LEETCODE_INCLUDE_144_H_
#define LEETCODE_INCLUDE_144_H_

/*144. 二叉树的前序遍历
简单
    给你二叉树的根节点 root ，返回它节点值的 前序 遍历。*/

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
class Solution_144 {
  struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 public:
  void traversal(TreeNode* node, vector<int> &vec){
      if(node == nullptr)
          return;
      vec.push_back(node->val);
      traversal(node->left, vec);
      traversal(node->right, vec);
  }
  vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      traversal(root, res);
      return res;
  }

  /*
 * 迭代遍历，用栈实现
 */
  vector<int> postorderTraversal_stack(TreeNode *root) {
      vector<int> res;
      if(!root)
          return res;
      stack<TreeNode *> traversal;
      traversal.push(root);
      while (!traversal.empty()) {
          TreeNode *cur = traversal.top();
          res.push_back(cur->val);
          traversal.pop();

          if (cur->right != nullptr)
              traversal.push(cur->right);
          if (cur->left != nullptr)
              traversal.push(cur->left);
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_144_H_
