//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_203_H_
#define LEETCODE_INCLUDE_203_H_
/*203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。*/

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
class Solution_203 {
 public:
  //O(n)

  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode *removeElements(ListNode *head, int val) {
      ListNode *new_head = new ListNode(0);
      new_head->next = head;
      ListNode *temp = new_head;
      while (temp->next != nullptr) {
          if (temp->next->val == val) {
              ListNode* del_node = temp->next;//释放删除节点
              temp->next = temp->next->next;
              delete (del_node);
          } else //遍历
              temp = temp->next;
      }
      ListNode* res = new_head->next;
      delete(new_head);
      return res;
  }
};
#endif //LEETCODE_INCLUDE_203_H_
