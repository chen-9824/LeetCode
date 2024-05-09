//
// Created by cfan on 2024/5/9.
//

#ifndef LEETCODE_INCLUDE_236_H_
#define LEETCODE_INCLUDE_236_H_

/*
 * 236. 二叉树的最近公共祖先
中等
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：
 “对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 提示：
树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。
 */

class Solution_236 {
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
   *
   * 公共节点，先找到指定节点，那就是自下而上寻找，后序遍历
输入参数为两个指定节点，当前节点，返回结果为公共祖先节点
终止条件为当前节点为空
单层递归逻辑
    判断终止条件，为真返回空
    左子节点遍历
    右子节点遍历
    当前节点计算，当前节点值是否等于指定节点值
        若等于，当前节点为祖先节点，返回当前节点
    判断是否为公共祖先节点
        若左右子节点遍历返回值不为空，则为最近公共祖先节点，返回
        若左为空右不为空，返回右
        若左不为空右为空，返回左
   */
  TreeNode *get(TreeNode *node, TreeNode *p, TreeNode *q) {
      //判断终止条件，为真返回空
      if (!node)
          return nullptr;
      //左子节点遍历
      TreeNode *left = get(node->left, p, q);
      //右子节点遍历
      TreeNode *right = get(node->right, p, q);
      //当前节点计算，当前节点值是否等于指定节点值
      if (node == p || node == q)//若等于，当前节点为祖先节点，返回当前节点
          return node;
      //判断是否为公共祖先节点
      //若左右子节点遍历返回值不为空，则为最近公共祖先节点，返回
      if (left && right)
          return node;
      else if (left)
          return left;
      else if (right)
          return right;
      return nullptr;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
      return get(root, p, q);
  }
};

#endif //LEETCODE_INCLUDE_236_H_
