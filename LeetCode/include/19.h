//
// Created by cfan on 2024/4/7.
//

#ifndef LEETCODE_INCLUDE_19_H_
#define LEETCODE_INCLUDE_19_H_
/*19. 删除链表的倒数第 N 个结点
中等
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution_19 {
 public:
  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* removeNthFromEnd(ListNode* head, int n) {

      ListNode* new_head = new ListNode(0);
      new_head->next = head;
      ListNode* fast = new_head;//双指针
      ListNode* slow = new_head;
      int temp = n;
      while (temp --){//fast先走n步，fast为nullptr时slow后即为待删除结点
          fast = fast->next;
      }
      while (fast->next != nullptr){
          fast = fast->next;
          slow = slow->next;
      }
      ListNode* temp_node = slow->next;
      slow->next = slow->next->next;
      delete(temp_node);
      ListNode* res = new_head->next;
      delete(new_head);
      return res;
  }
};
#endif //LEETCODE_INCLUDE_19_H_
