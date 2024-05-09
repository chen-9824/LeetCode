//
// Created by cfan on 2024/5/9.
//

#ifndef LEETCODE_INCLUDE_501_H_
#define LEETCODE_INCLUDE_501_H_

/*
 * 501. 二叉搜索树中的众数
简单
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。
假定 BST 满足如下定义：
结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树
 */

class Solution_501 {
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
   * 如果是不是二叉搜索树，那就用map保存出现频率
   * 但是是二叉搜索树，那就是有序的，即重复元素会相邻出现，方便计算出现频率
   * 并且对众数而言只需得到最大出现频率的数保存起来就行
   * 中序遍历，方便利用有序特性,定义一个前指针，与当前节点比较
输入参数为当前节点及众数集合，无输出
终止条件为输入节点为空
单层递归逻辑：
判断终止条件
遍历左节点
遍历中节点
判断上一节点是否为空，
若不为空，比较节点值,若相等，出现频率加一,如果当前节点值与前一个节点值不相等，说明前节点值不再出现,出现频率=1
更新上一节点
比较最大出现频率，
若大于最大出现频，清空当前结果集，加入上一节点值，若等于最大出现频，加入上一节点值，
遍历右节点
 */
  TreeNode *per = nullptr;
  int count = 1;//默认1是因为根节点没有前一个节点
  int max_count = 0;
  void get(TreeNode *node, vector<int> &res) {
      //判断终止条件
      if (!node)
          return;
      //遍历左节点
      get(node->left, res);
      //遍历中节点
      //判断上一节点是否为空，
      //若不为空，比较节点值
      if (per) {
          //若相等，出现频率加一
          if (node->val == per->val) {
              count += 1;
          } else{//如果当前节点值与前一个节点值不相等
              count = 1;
          }
      }
      //更新上一节点
      per = node;

      //比较最大出现频率
      //若大于，清空当前结果集，加入上一节点值，若等于，加入上一节点值，
      if (count > max_count) {
          res.clear();
          res.push_back(node->val);
          max_count = count;
      } else if (count == max_count) {
          res.push_back(node->val);
      }

      //遍历右节点
      get(node->right, res);
      return;
  }
  vector<int> findMode(TreeNode *root) {
      vector<int> res;
      get(root, res);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_501_H_
