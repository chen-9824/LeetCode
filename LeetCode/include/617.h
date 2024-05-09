//
// Created by cfan on 2024/5/8.
//

#ifndef LEETCODE_INCLUDE_617_H_
#define LEETCODE_INCLUDE_617_H_

/*617. 合并二叉树
    简单
给你两棵二叉树： root1 和 root2 。
想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。
 合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
返回合并后的二叉树。
注意: 合并过程必须从两个树的根节点开始。*/

class Solution_617 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*  输入参数为俩个树的节点，返回值为新二叉树根节点
      终止条件为两个节点均为空
  单层递归逻辑：
  判断终止条件，若为真则返回
      更新新二叉树当前节点值，值为传入两节点值之和
      遍历左子树
  遍历右子树
      返回根节点

      优化方向，目前是新建了一个树，可以在原有的树上操作

      */

  TreeNode *build(TreeNode *root1, TreeNode *root2) {
      //终止条件为两个节点均为空
      if (!root1 && !root2)
          return nullptr;
      //更新新二叉树当前节点值，值为传入两节点值之和
      int val_1 = 0;
      TreeNode *root1_left = nullptr;//可能该节点本身为空，访问其左右子树会出错
      TreeNode *root1_right = nullptr;
      if (root1) {
          val_1 = root1->val;
          root1_left = root1->left;
          root1_right = root1->right;
      }

      int val_2 = 0;
      TreeNode *root2_left = nullptr;
      TreeNode *root2_right = nullptr;
      if (root2) {
          val_2 = root2->val;
          root2_left = root2->left;
          root2_right = root2->right;
      }

      TreeNode *root = new TreeNode(val_1 + val_2);
      //遍历左子树
      root->left = build(root1_left, root2_left);
      //遍历右子树
      root->right = build(root1_right, root2_right);
      return root;
  }

  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
      return build(root1, root2);
  }
};

#endif //LEETCODE_INCLUDE_617_H_
