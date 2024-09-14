//
// Created by cfan on 2024/4/17.
//

#ifndef LEETCODE_INCLUDE_102_H_
#define LEETCODE_INCLUDE_102_H_

/*102. 二叉树的层序遍历
    中等
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
（即逐层地，从左到右访问所有节点）。*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>
class Solution_102 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
  };

  /*
   * 怎么判断哪些结点是同一层的
   * 或者说怎么获取一层结点
   * 把每层节点压入队列，每次循环读一整层节点，就不需要判断该节点是哪层的了，也拿到了一层所有节点
   * 第二种方法，递归，把遍历每一层当一次递归逻辑，为空则是终止条件
   */
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode *> record;
    record.push(root);
    while (!record.empty()) {
      vector<int> temp;
      int size = record.size();
      while (size--) {
        TreeNode *node = record.front();
        temp.push_back(node->val);
        record.pop();
        if (node->left) record.push(node->left);
        if (node->right) record.push(node->right);
      }
      res.push_back(temp);
    }
    return res;
  }

  void order(int depth, TreeNode *node, vector<vector<int>> &vec) {
    if (!node) return;
    if (depth >= vec.size())  // 多维数组需要初始化
      vec.push_back(vector<int>());
    vec[depth].push_back(node->val);
    if (node->left) order(depth + 1, node->left, vec);
    if (node->right) order(depth + 1, node->right, vec);
  }

  vector<vector<int>> levelOrder_di_gui(TreeNode *root) {
    vector<vector<int>> res;
    int depth = 0;
    order(depth, root, res);
    return res;
  }
};

#endif  // LEETCODE_INCLUDE_102_H_
