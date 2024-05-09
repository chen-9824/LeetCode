//
// Created by cfan on 2024/5/9.
//

#ifndef LEETCODE_INCLUDE_235_H_
#define LEETCODE_INCLUDE_235_H_

/*
 * 235. 二叉搜索树的最近公共祖先
中等
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：
 “对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 */

class Solution_235 {
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
   * 二叉搜索树，有序，从上往下找，只要节点在[p, q]范围内，为其最近公共祖先节点
输入参数为两个指定节点，当前节点，返回结果为公共祖先节点
终止条件为当前节点为空
单层递归逻辑
    判断终止条件，为真返回空
    判断当前节点是否在[p, q]范围内
        若当前节点大于指定节点p，q，说明指定节点在左子树，递归遍历左子树
        若当前节点小于指定节点p，q，说明指定节点在右子树，递归遍历右子树
        若在范围内，返回当前节点
   */
  TreeNode *get(TreeNode *cur, TreeNode *p, TreeNode *q){
      //判断终止条件，为真返回空
      if(!cur)
          return nullptr;
      //判断当前节点是否在[p, q]范围内
      //若当前节点大于指定节点p，q，说明指定节点在左子树，递归遍历左子树
      if(cur->val > p->val && cur->val > q->val){
          TreeNode *node = get(cur->left, p, q);
          if(node)
              return node;
      }
      //若当前节点小于指定节点p，q，说明指定节点在右子树，递归遍历右子树
      if(cur->val < p->val && cur->val < q->val){
          TreeNode *node = get(cur->right, p, q);
          if(node)
              return node;
      }
      //若在范围内，返回当前节点
      return cur;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
      return get(root, p, q);
  }
};

#endif //LEETCODE_INCLUDE_235_H_
