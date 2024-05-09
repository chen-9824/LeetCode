//
// Created by cfan on 2024/5/8.
//

#ifndef LEETCODE_INCLUDE_106_H_
#define LEETCODE_INCLUDE_106_H_

/*106. 从中序与后序遍历序列构造二叉树
    中等
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

 提示:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历
 */

class Solution_106 {
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
   * 输入参数为两个遍历数组，返回结果为根节点
终止条件为遍历数组剩一个元素，那需要保证传入参数不为空
单层递归逻辑：
先判断终止条件，若终止，返回根节点
先取后序数组最后一个元素作为根节点
通过该节点切割中序数组
根据切割得到的左右中序数组数量切割后序数组
左子树遍历，输入为左中序数组，左后序数组，返回为左子节点
右子树遍历，输入为右中序数组，右后序数组，返回为右子节点
返回根节点
   */

  TreeNode *build_tree(vector<int> &inorder, vector<int> &postorder) {
      //先取后序数组最后一个元素作为根节点
      TreeNode *root = new TreeNode(*(postorder.end() - 1));
      //终止条件为遍历数组剩一个元素，那需要保证传入参数不为空
      if (inorder.size() == 1) {
          return root;
      }
      //通过该节点切割中序数组
      int mid_index = 0;
      while (mid_index < inorder.size()) {
          if (inorder[mid_index] == root->val)
              break;
          mid_index += 1;
      }
      vector<int> inorder_left(inorder.begin(), inorder.begin() + mid_index);//注意去掉已经用过的根节点
      vector<int> inorder_right(inorder.begin() + mid_index + 1, inorder.end());

      //根据切割得到的左右中序数组数量切割后序数组
      vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
      vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end() - 1);//注意去掉已经用过的根节点

      //左子树遍历,需要保证传入参数不为空
      if (inorder_left.empty())
          root->left = nullptr;
      else
          root->left = build_tree(inorder_left, postorder_left);

      //右子树遍历,需要保证传入参数不为空
      if (inorder_right.empty())
          root->right = nullptr;
      else
          root->right = build_tree(inorder_right, postorder_right);

      return root;

  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      if(inorder.size() == 0){
          return nullptr;
      }
      return build_tree(inorder, postorder);
  }
};

#endif //LEETCODE_INCLUDE_106_H_
