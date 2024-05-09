//
// Created by cfan on 2024/4/18.
//

#ifndef LEETCODE_INCLUDE_116_H_
#define LEETCODE_INCLUDE_116_H_

/*116. 填充每个节点的下一个右侧节点指针
    中等
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution_116 {
 public:
  class Node {
   public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
  };

  Node *connect(Node *root) {
      if (!root)
          return root;
      queue<Node *> record;
      record.push(root);
      while (!record.empty()) {
          int size = record.size();
          while (size--) {
              Node *node = record.front();
              record.pop();
              if (size > 0)
                  node->next = record.front();
              if (node->left)
                  record.push(node->left);
              if (node->right)
                  record.push(node->right);
          }
      }
      return root;
  }
};

#endif //LEETCODE_INCLUDE_116_H_
