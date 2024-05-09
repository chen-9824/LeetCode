//
// Created by cfan on 2024/4/17.
//

#ifndef LEETCODE_INCLUDE_429_H_
#define LEETCODE_INCLUDE_429_H_
/*429. N 叉树的层序遍历
中等
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution_429 {
 public:
  class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
  };
/*
 * 102  层序遍历类似
 */
  vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>> res;
      if(!root)
          return res;
      queue<Node*> record;
      record.push(root);
      while (!record.empty()){
          vector<int> temp;
          int size = record.size();
          while (size--){
              Node* node = record.front();
              record.pop();
              temp.push_back(node->val);
              for(auto i : node->children){
                  if(i)
                      record.push(i);
              }
          }
          res.push_back(temp);
      }
      return res;
  }
};

#endif //LEETCODE_INCLUDE_429_H_
