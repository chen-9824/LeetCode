//
// Created by cfan on 2024/5/8.
//

#ifndef LEETCODE_INCLUDE_654_H_
#define LEETCODE_INCLUDE_654_H_

/*654. 最大二叉树
    中等
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

 提示：
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
nums 中的所有整数 互不相同
 */

class Solution_654 {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*  输入参数为不重复的整数数组 nums，返回结果为根节点
      终止条件为遍历数组剩一个元素，那需要保证传入参数不为空
      单层递归逻辑：
  寻找 nums最大值作为根节点，暴力比较
      判断终止条件，若终止，返回根节点
      通过该节点切割 nums
      左子树遍历，输入为左数组，返回为左子节点
      右子树遍历，输入为右数组，返回为右子节点
      返回根节点*/
  TreeNode *build(vector<int> &nums) {
      //寻找 nums最大值作为根节点，暴力比较
      int max_val = 0;
      int max_val_index = 0;
      int temp = 0;
      for(auto i : nums){
          if(i > max_val) {
              max_val = i;
              max_val_index = temp;
          }
          temp += 1;
      }
      TreeNode *root = new TreeNode(max_val);
      //判断终止条件，若终止，返回根节点
      if(nums.size() == 1)
          return root;
      //通过该节点切割 nums
      vector<int> nums_left(nums.begin(), nums.begin() + max_val_index);
      vector<int> nums_right(nums.begin() + max_val_index + 1, nums.end());
      //左子树遍历，输入为左数组，返回为左子节点
      if (nums_left.empty())
          root->left = nullptr;
      else
          root->left = build(nums_left);
      //右子树遍历，输入为右数组，返回为右子节点
      if (nums_right.empty())
          root->right = nullptr;
      else
          root->right = build(nums_right);

      return root;

  }

  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
      if(nums.empty()){
          return nullptr;
      }
      return build(nums);
  }
};

#endif //LEETCODE_INCLUDE_654_H_
