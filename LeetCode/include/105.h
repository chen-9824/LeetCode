//
// Created by cfan on 2024/5/8.
//

#ifndef LEETCODE_INCLUDE_105_H_
#define LEETCODE_INCLUDE_105_H_

/*105. 从前序与中序遍历序列构造二叉树
    中等
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。*/

class Solution_105 {
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
先取前序数组第一个元素作为根节点
通过该节点切割中序数组
根据切割得到的左右中序数组数量切割前序数组
左子树遍历，输入为左中序数组，左前序数组，返回为左子节点
右子树遍历，输入为右中序数组，右前序数组，返回为右子节点
返回根节点
   */
  TreeNode *build(vector<int> &preorder, vector<int> &inorder){
      //先取后序数组最后一个元素作为根节点
      TreeNode *root = new TreeNode(*(preorder.begin()));
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

      //根据切割得到的左右中序数组数量切割中序数组
      vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + inorder_left.size() + 1);//注意去掉已经用过的根节点
      vector<int> preorder_right(preorder.begin() + inorder_left.size() + 1, preorder.end());

      //左子树遍历,需要保证传入参数不为空
      if (inorder_left.empty())
          root->left = nullptr;
      else
          root->left = build(preorder_left, inorder_left);

      //右子树遍历,需要保证传入参数不为空
      if (inorder_right.empty())
          root->right = nullptr;
      else
          root->right = build(preorder_right, inorder_right);

      return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      if(inorder.size() == 0){
          return nullptr;
      }
      return build(preorder, inorder);
  }
};

#endif //LEETCODE_INCLUDE_105_H_
