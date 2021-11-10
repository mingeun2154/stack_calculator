// 2018203023 Mingeun Park
// This is the interface for the Node class

#ifndef NODE_H_
#define NODE_H_

#include <stddef.h>

namespace linkedList
{

  template <class ValueType>
  class Node
  {
  public:
    // Constructors
    Node();
    Node(ValueType new_data);
    Node(ValueType new_data, Node *prevLink, Node *nextLink);
    // Accessor
    ValueType get_data() const { return data_field; }
    Node *prevLink() const { return prevLink_field; }
    Node *nextLink() const { return nextLink_field; }
    // Mutator
    void set_data(ValueType new_data) { data_field = new_data; }
    void set_prevLink(Node *new_link) { prevLink_field = new_link; }
    void set_nextLink(Node *new_link) { nextLink_field = new_link; }

  private:
    ValueType data_field;
    Node<ValueType> *prevLink_field;
    Node<ValueType> *nextLink_field;
  };

  template <class ValueType>
  size_t list_length(const Node<ValueType> *head_ptr);
  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Returns length of the list

  template <class ValueType>
  Node<ValueType> *list_search(Node<ValueType> *head_ptr, ValueType target);

  template <class ValueType>
  const Node<ValueType> *list_search(const Node<ValueType> *head_ptr, ValueType target);
  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Returns a pointer to the first node that contains the target
  // If no node equals the target, returns NULL

  template <class ValueType>
  Node<ValueType> *list_locate(Node<ValueType> *head_ptr, size_t position);
  template <class ValueType>
  const Node<ValueType> *list_locate(const Node<ValueType> *head_ptr, size_t position);
  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // position is natural number(1,2,3, ...)
  // Returns a pointer to the desired node
  // If position>(length of the list) or position<=0 or head_ptr=NULL, return NULL

  template <class ValueType>
  void list_head_insert(Node<ValueType> *&head_ptr, const ValueType &entry);
  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: A new node containing entry has been added at the head of the list

  template <class ValueType>
  void list_insert(Node<ValueType> *prev_ptr, const ValueType &entry);
  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: A new node containing entry has been added after the node
  // pointed to by prev_ptr

  template <class ValueType>
  void list_head_remove(Node<ValueType> *&head_ptr);
  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: Head is removed from the list

  template <class ValueType>
  void list_remove(Node<ValueType> *prev_ptr);
  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Postcondition: A node pointed to by prev_node has been removed
  // from the list and its storage returned to the freestore

  template <class ValueType>
  void list_clear(Node<ValueType> *&head_ptr);
  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Postcondition: All nodes have been removed, returned to the freestore

  template <class ValueType>
  void list_copy(Node<ValueType> *source_ptr, Node<ValueType> *&head_ptr);
  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Postcondition: head_ptr points to a duplicate of list pointed to by source_ptr
  // Duplicated list is nodes created by dynamic allocation

  template <class ValueType>
  void show_nodes_head(const Node<ValueType> *head_ptr);
  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: print all nodes' data from the head
} // LinkedList

#endif // NODE_H_