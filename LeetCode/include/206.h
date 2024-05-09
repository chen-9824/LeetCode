//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_206_H_
#define LEETCODE_INCLUDE_206_H_

/*206. 反转链表
简单
    给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。*/

class Solution_206 {
 public:
  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  //O(n)
  ListNode* reverseList(ListNode* head) {
      ListNode *cur = head;
      ListNode *tail = nullptr;
      while (cur != nullptr){
          ListNode *temp = cur->next;
          cur->next = tail;
          tail = cur;
          cur = temp;
      }
      return tail;
  }
};

#endif //LEETCODE_INCLUDE_206_H_
