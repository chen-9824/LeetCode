//
// Created by cfan on 2024/4/8.
//

#ifndef LEETCODE_INCLUDE_707_H_
#define LEETCODE_INCLUDE_707_H_
/*707. 设计链表
中等
    你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：
MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。*/


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */



class MyLinkedList {
 public:
  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *node) : val(x), next(node) {};
  };

  MyLinkedList() : list_size(0) {
      virtual_head = new ListNode();
  };

  int get(int index) {
      //下标从 0 开始
      if (index >= list_size) {
          std::cout << "out of range index." << std::endl;
          return -1;
      }

      ListNode *temp = this->virtual_head;
      while (index > 0) {
          if (temp->next != nullptr) {
              temp = temp->next;
          } else
              return -1;
          index -= 1;
      }

      return temp->next->val;
  }

  void addAtHead(int val) {
      ListNode *new_head = new ListNode(val);
      new_head->next = this->virtual_head->next;
      this->virtual_head->next = new_head;
      list_size += 1;
  }

  void addAtTail(int val) {
      ListNode *new_node = new ListNode(val);
      ListNode *temp = virtual_head;
      while (temp->next != nullptr)
          temp = temp->next;
      temp->next = new_node;
      list_size += 1;
  }

  void addAtIndex(int index, int val) {
      if (index > list_size) {
          std::cout << "out of range index." << std::endl;
          return;
      }

      ListNode *new_node = new ListNode(val);
      ListNode *temp = virtual_head;
      while (index--)
          temp = temp->next;

      new_node->next = temp->next;
      temp->next = new_node;
      list_size += 1;
  }

  void deleteAtIndex(int index) {
      if (index >= list_size) {
          std::cout << "out of range index." << std::endl;
          return;
      }

      ListNode *temp = virtual_head;
      while (index--)
          temp = temp->next;

      ListNode *del_node = temp->next;
      temp->next = temp->next->next;
      delete (del_node);
      list_size -= 1;
  }

 private:
  int list_size;
  ListNode *virtual_head;
};

#endif //LEETCODE_INCLUDE_707_H_
