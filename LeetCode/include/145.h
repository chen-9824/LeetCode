//
// Created by cfan on 2024/4/16.
//

#ifndef LEETCODE_INCLUDE_145_H_
#define LEETCODE_INCLUDE_145_H_

/*145. 二叉树的后序遍历
简单
    给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。*/
#include <algorithm>
#include <queue>
class Solution_145 {
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
  };

 public:
  /*
   * 递归遍历，确定终止条件及单次递归逻辑
   */
  void traversal(TreeNode *node, vector<int> &vec) {
    if (node == nullptr) return;

    traversal(node->left, vec);
    traversal(node->right, vec);
    vec.push_back(node->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    traversal(root, res);
    return res;
  }

  /*
   * 迭代遍历，用栈实现
   */
  vector<int> postorderTraversal_stack(TreeNode *root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode *> traversal;
    traversal.push(root);
    while (!traversal.empty()) {
      TreeNode *node = traversal.top();
      traversal.pop();
      res.push_back(node->val);
      if (node->left != nullptr) traversal.push(node->left);
      if (node->right != nullptr) traversal.push(node->right);
    }
    /*for(int i = 0; i < res.size() / 2; ++i){
        swap(res[i], res[res.size() - i - 1]);
    }*/
    reverse(res.begin(), res.end());  // 将结果反转之后就是左右中的顺序了
    return res;
  }
};

#endif  // LEETCODE_INCLUDE_145_H_
