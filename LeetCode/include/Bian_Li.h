//
// Created by cfan on 2024/4/16.
//

#ifndef LEETCODE_INCLUDE_BIAN_LI_H_
#define LEETCODE_INCLUDE_BIAN_LI_H_

struct tree_node {
  int val;
  tree_node *left;
  tree_node *right;
  tree_node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void forward_traversal_part(tree_node *node, vector<int> vec) {
    tree_node *cur = node;
    if (cur != nullptr)
        return;

    vec.push_back(cur->val);
    forward_traversal_part(cur->left, vec);
    forward_traversal_part(cur->right, vec);
}

vector<int> forward_traversal(tree_node *root){
    vector<int> res;
    forward_traversal_part(root, res);
    return res;
}

#endif //LEETCODE_INCLUDE_BIAN_LI_H_
