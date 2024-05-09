//
// Created by cfan on 2024/5/8.
//

#ifndef LEETCODE_INCLUDE_700_H_
#define LEETCODE_INCLUDE_700_H_

/*700. 二叉搜索树中的搜索
    简单

给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。*/

class Solution_700 {
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
   * 中序遍历
输入参数为当前节点及目标值，返回值为找到的节点
终止逻辑为当前节点为空，返回空
单层递归逻辑：
判断终止条件，若为真返回空
判断当前节点值与目标值是否相等
若相等，直接返回该节点
若目标值大于当前节点值，遍历右子树
若小于，遍历左子树
返回得到的节点
   */
  TreeNode *get(TreeNode *root, int &val){
      //终止逻辑为当前节点为空，返回空
      if(!root)
          return nullptr;
      //判断当前节点值与目标值是否相等
      TreeNode *node = nullptr;
      if(val == root->val)
          return root;
      else if(val > root->val)
          node = get(root->right, val);
      else if(val < root->val)
          node = get(root->left, val);
      return node;
  }
  TreeNode *searchBST(TreeNode *root, int val) {
      return get(root, val);
  }
};

#endif //LEETCODE_INCLUDE_700_H_
