//
// Created by cfan on 2024/5/10.
//

#ifndef LEETCODE_INCLUDE_108_H_
#define LEETCODE_INCLUDE_108_H_

/*
 * 108. 将有序数组转换为二叉搜索树
简单
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵平衡二叉搜索树。
 */

class Solution_108 {
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
 * 关键时平衡，左右节点数要相等
 输入参数为递增数组，左右区间下标，返回值为中间节点
终止条件为左下标大于右下标
单层递归逻辑：
    判断终止条件，为真返回空
    取左右下标平均值mid，构造当前节点
    遍历当前节点左子节点，应该是[左，mid - 1]区间内
    遍历当前节点左子节点，应该是[mid + 1， 右]区间内
    返回当前节点
 */
  TreeNode *get(vector<int> &nums, int left_index, int right_index){
      if(left_index > right_index)
          return nullptr;
      int mid = left_index + ((right_index - left_index) / 2);
      TreeNode *node = new TreeNode(nums[mid]);
      node->left = get(nums, left_index, mid - 1);
      node->right = get(nums, mid + 1, right_index);
      return node;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
      return get(nums, 0, nums.size() - 1);
  }
};

#endif //LEETCODE_INCLUDE_108_H_
