//
// Created by cfan on 2024/4/7.
//

#ifndef LEETCODE_INCLUDE_02_07_H_
#define LEETCODE_INCLUDE_02_07_H_

/*面试题 02.07. 链表相交
简单
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_02_07 {
 public:
  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *new_headA = new ListNode(0);//添加虚拟头节点可以避免很多特殊情况，例如给定节点为空，给定头节点为相同节点
      new_headA->next = headA;
      ListNode *new_headB = new ListNode(0);
      new_headB->next = headB;

      ListNode* temp = new_headB;
      while (new_headA->next != nullptr){
          while (temp->next != nullptr){
              if(new_headA->next == temp->next)
                  return new_headA->next;
              temp = temp->next;
          }
          temp = new_headB;
          new_headA = new_headA->next;
      }
      return nullptr;
  }
};
#endif //LEETCODE_INCLUDE_02_07_H_
