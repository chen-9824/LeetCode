//
// Created by cfan on 2024/4/22.
//

#ifndef LEETCODE_INCLUDE_513_H_
#define LEETCODE_INCLUDE_513_H_

/*513. 找树左下角的值
    中等
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。*/

class Solution_513 {
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
   * 层序遍历用的是队列，头节点就是该层最左节点，只需判断是否为最后一层
   */
  int findBottomLeftValue(TreeNode *root) {
      int res = 0;
      if (!root)
          return res;
      queue<TreeNode *> record;
      record.push(root);
      while (!record.empty()) {
          int size = record.size();
          int count = 0;
          for (int i = 0; i < size; ++i) {
              TreeNode *node = record.front();
              record.pop();
              if (i == 0)
                  res = node->val;
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
          }
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_513_H_
