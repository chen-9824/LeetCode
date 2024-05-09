//
// Created by cfan on 2024/4/7.
//

#ifndef LEETCODE_INCLUDE_24_H_
#define LEETCODE_INCLUDE_24_H_



class Solution_24 {
 public:
  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* swapPairs(ListNode* head) {

      ListNode* new_head = new ListNode(0);
      new_head->next = head;
      ListNode* temp = new_head;
      while (temp->next != nullptr && temp->next->next != nullptr){
          ListNode* temp_1 = temp->next;
          ListNode* temp_2 = temp->next->next->next;

          temp->next = temp->next->next;
          temp->next->next = temp_1;
          temp->next->next->next = temp_2;

          temp = temp->next->next;
      }
      ListNode* res = new_head->next;
      delete(new_head);
      return res;
  }
};
#endif //LEETCODE_INCLUDE_24_H_
