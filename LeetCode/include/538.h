//
// Created by cfan on 2024/5/10.
//

#ifndef LEETCODE_INCLUDE_538_H_
#define LEETCODE_INCLUDE_538_H_

/*
 * 538. 把二叉搜索树转换为累加树
中等
给出二叉 搜索 树的根节点，该树的节点值各不相同，
 请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和
提醒一下，二叉搜索树满足下列约束条件：
节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
 */

class Solution_538 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  TreeNode* pre;
  void get(TreeNode *root) {
      if(!root)
          return;
      get(root->right);

      if(pre){
          root->val += pre->val;
      }
      pre = root;

      get(root->left);
  }

  TreeNode *convertBST(TreeNode *root) {
      get(root);
      return root;
  }
};

#endif //LEETCODE_INCLUDE_538_H_
