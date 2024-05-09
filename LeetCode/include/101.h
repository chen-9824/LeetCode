//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_101_H_
#define LEETCODE_INCLUDE_101_H_

/*101. 对称二叉树
    简单
给你一个二叉树的根节点 root ， 检查它是否轴对称。*/
class Solution_101 {
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
 * 队列存左子树,栈存右子树,这样可以比较值，但是队列跟栈的内部还需要区分左右子树，这个没法区分了
 * 本质上还是遍历节点，只不过需要分左右子树遍历，并且遍历顺序刚好相反
 * 那就可以分左右子树进行递归,分别比较左右子树的内侧节点与外侧节点是否相等
 * 返回参数为是否对称，输入参数为左右节点
 * 单次递归逻辑为左节点的左子树与右节点的右子树是否相等，左节点的右子树与右节点的左子树是否相等
 * 终止条件就是当传入节点一个为空一个不为空时，或者两个都为空时,两个都不为空且值不相等
 * 还可以使用迭代法，通过队列比较，未实现
 */

  bool order(TreeNode *left_node, TreeNode *right_node) {
      if (!left_node && !right_node)
          return true;
      else if (!left_node || !right_node)
          return false;
      else if(left_node->val != right_node->val)
          return false;
      else {//两个都不为空且值相等
          bool outside = order(left_node->left, right_node->right);
          bool inside = order(left_node->right, right_node->left);
          return outside & inside;
      }
  }

  bool isSymmetric(TreeNode *root) {
      if (!root)
          return false;
      bool res = order(root->left, root->right);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_101_H_
