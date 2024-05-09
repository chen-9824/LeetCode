//
// Created by cfan on 2024/5/9.
//

#ifndef LEETCODE_INCLUDE_450_H_
#define LEETCODE_INCLUDE_450_H_

/*
 * 450. 删除二叉搜索树中的节点
中等
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
 返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。
 */

class Solution_450 {
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
   * 五种情况，
    1.未找到指定节点，返回空
    2.指定节点无子节点，直接删掉指定节点就好，返回空
    3.指定节点有左子节点，无右，删除指定节点，返回左子节点
    4.指定节点有右子节点，无左，删除指定节点，返回右子节点
    5.指定节点有两个子节点，需要将指定节点的右子节点挂到其左子节点的右叶子节点上，返回左子节点

输入参数为指定节点，当前节点，返回值为新节点
终止条件为空
单层递归逻辑：
    判断终止条件，为真，返回空
    判断当前节点是否为指定节点
        若是，五种情况
    如果给定值小于当前节点，左子节点遍历
    如果给定值大于当前节点，右子节点遍历
    返回当前节点
   */
  TreeNode *get(TreeNode *root, int key) {
      if (!root)
          return nullptr;
      //判断当前节点是否为指定节点
      if (root->val == key) {
          //2.指定节点无子节点，直接删掉指定节点就好，返回空
          if (!root->left && !root->right) {
              delete root;
              return nullptr;
          }
              //5.指定节点有两个子节点，需要将指定节点的右子节点挂到其左子节点的右叶子节点上，返回左子节点
          else if (root->left && root->right) {
              TreeNode *temp = root->left;
              while (temp->right) {
                  temp = temp->right;
              }
              temp->right = root->right;
              temp = root->left;
              delete (root);
              return temp;
          }
          //3.指定节点有左子节点，无右，删除指定节点，返回左子节点
          else if (root->left) {
              TreeNode *temp = root->left;
              delete root;
              return temp;
          }
              //4.指定节点有右子节点，无左，删除指定节点，返回右子节点
          else if (root->right) {
              TreeNode *temp = root->right;
              delete root;
              return temp;
          }
      }

      //如果给定值小于当前节点，左子节点遍历
      if(key < root->val)
          root->left = get(root->left, key);
      if(key > root->val)
          root->right = get(root->right, key);
      return root;
  }
  TreeNode *deleteNode(TreeNode *root, int key) {

      return get(root, key);
  }
};

#endif //LEETCODE_INCLUDE_450_H_
