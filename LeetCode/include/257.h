//
// Created by cfan on 2024/4/19.
//

#ifndef LEETCODE_INCLUDE_257_H_
#define LEETCODE_INCLUDE_257_H_

/*257. 二叉树的所有路径
    简单
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。

 输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]

 */

class Solution_257 {
 public:
  struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  /*后序遍历
   * 返回值是路径，传入参数当前节点
   * 终止条件：节点空
   * 单层递归逻辑：
   * 左子节点递归获得路径，可能单次返回多条路径
   * 右子节点递归获得路径，可能单次返回多条路径
   * 返回null/左子节点路径/右子节点路径 + 当前节点，可能单次返回多条路径
   */

  vector<string> get_path(TreeNode* node){
      vector<string> path;
      if(!node)
          return path;
      vector<string> left_path = get_path(node->left);
      vector<string> right_path = get_path(node->right);

      for(int i = 0; i < left_path.size(); ++i){
          string s = to_string(node->val) + "->" + left_path[i];
          path.push_back(s);
      }

      for(int i = 0; i < right_path.size(); ++i){
          string s = to_string(node->val) + "->" + right_path[i];
          path.push_back(s);
      }

      if(right_path.empty() && left_path.empty()){
          string s = to_string(node->val);
          path.push_back(s);
      }
      return path;
  }

  vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      if(!root)
          return res;
      res = get_path(root);
      return res;
  }

  /*
   * 后序遍历
   * 递归加回溯
   * 无返回参数，输入当前节点，到达当前节点路径，结果路径
因为是前序遍历到叶子节点，所以终止条件可以设为当遇到叶子节点时终止
单层递归：
前序遍历，当前节点路径先加入当前节点
判断是否为叶子节点
左节点递归，回溯
右节点递归，回溯
   */


  void get_path_hou_xu(TreeNode* node,  vector<int> &path, vector<string> &res){
      path.push_back(node->val);//后续逻辑保证不为空
      if(!node->left && !node->right) {
          string s;
          for (int i = 0; i < path.size() - 1; i++) {
              s += to_string(path[i]);
              s += "->";
          }
          s += to_string(path[path.size() - 1]);
          res.push_back(s);
          return;
      }

      if(node->left){
          get_path_hou_xu(node->left, path, res);
          path.pop_back();//回溯
      }
      if(node->right){
          get_path_hou_xu(node->right, path, res);
          path.pop_back();//回溯
      }
  }

  vector<string> binaryTreePaths_hou_xu(TreeNode* root) {
      vector<string> res;
      vector<int> path;
      if(!root)
          return res;
      get_path_hou_xu(root, path, res);
      return res;
  }
};

#endif //LEETCODE_INCLUDE_257_H_
