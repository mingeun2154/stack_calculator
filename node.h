// 2018203023 Mingeun Park
// This is the interface & implementation for the Node class

#ifndef _NODE__H_
#define _NODE__H_

#include <stdlib.h>
#include <iostream>
#include <stddef.h>

using std::cout;

namespace linkedList
{

  template <class ValueType>
  class Node
  {
  public:
    // Constructors
    Node(){
    data_field=0.0;
    prevLink_field=NULL;
    nextLink_field=NULL;
    }
    Node(ValueType new_data){
      data_field=new_data;
      prevLink_field=NULL;
      nextLink_field=NULL;
    }
    Node(ValueType new_data, Node* prevLink, Node* nextLink){
      data_field=new_data;
      prevLink_field=prevLink;
      nextLink_field=nextLink;
    }
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
  }; // Node 

  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Returns length of the list
  template<class ValueType>
  size_t list_length(const Node<ValueType>* head_ptr){
    if(head_ptr==NULL)
      return 0;
    else{
      size_t length=1;
      const Node<ValueType>* cursor=head_ptr;
      while(cursor->nextLink()!=NULL){
        cursor=cursor->nextLink();
        length+=1;
      }
      return length;
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Returns a pointer to the first node that contains the target
  // If no node equals the target, returns NULL
  template<class ValueType>
  Node<ValueType>* list_search(Node<ValueType>* head_ptr, ValueType target){
    Node<ValueType>* cursor=head_ptr;
    if(cursor==NULL)
      return NULL;
    else{
      while(cursor!=NULL){
        if(cursor->get_data()==target)
          return cursor;
        else
          cursor=cursor->nextLink();
      }
      return NULL;
    }
  }
  //Const version of list_search()
  template<class ValueType>
  const Node<ValueType>* list_search(const Node<ValueType>* head_ptr, ValueType target){
    const Node<ValueType>* cursor=head_ptr;
    if(cursor==NULL)
      return NULL;
    else{
      while(cursor!=NULL){
        if(cursor->get_data()==target)
          return cursor;
        else
          cursor=cursor->nextLink();
      }
      return NULL;
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // position is natural number(1,2,3, ...)
  // Returns a pointer to the desired node
  // If position>(length of the list) or position<=0 or head_ptr=NULL, return NULL
  template<class ValueType>
  Node<ValueType>* list_locate(Node<ValueType>* head_ptr, size_t position){
    //Head's position is 1
    Node<ValueType>* cursor=head_ptr;
    if(head_ptr==NULL||position<=0||position>list_length(head_ptr))
      return NULL;
    else if(position==1) //position=1 means the first node(head node)
      return head_ptr;
    else{
      while(position>1){
        cursor=cursor->nextLink();
        position-=1;
      }
    return cursor;
    }
  }
  template<class ValueType>
  const Node<ValueType>* list_locate(const Node<ValueType>* head_ptr, size_t position){
    //Head's position is 1
    const Node<ValueType>* cursor=head_ptr;
    if(head_ptr==NULL||position<=0||position>list_length(head_ptr))
      return NULL;
    else if(position==1) //position=1 means the first node(head node)
      return head_ptr;
    else{
      while(position>1){
        cursor=cursor->nextLink();
        position-=1;
      }
    return cursor;
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: A new node containing entry has been added at the head of the list
  template<class ValueType>
  void list_head_insert(Node<ValueType>*& head_ptr, const ValueType& entry){
    Node<ValueType>* original_head=head_ptr;
    head_ptr=new Node<ValueType>(entry, NULL, head_ptr);
    original_head->set_prevLink(head_ptr);
  }

  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: A new node containing entry has been added after the node
  // pointed to by prev_ptr
  template<class ValueType>
  void list_insert(Node<ValueType>* prev_ptr, const ValueType& entry){
    //Check the length of list
    if(prev_ptr->nextLink()==NULL) //Insert at the end of the list
      prev_ptr->set_nextLink(new Node<ValueType>(entry, prev_ptr, NULL));
    else{ //Insert between two different nodes
      Node<ValueType>* nextNode=prev_ptr->nextLink();
      prev_ptr->set_nextLink(new Node<ValueType>(entry, prev_ptr, nextNode));
      nextNode->set_prevLink(prev_ptr->nextLink());
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: Head is removed from the list
  template<class ValueType>
  void list_head_remove(Node<ValueType>*& head_ptr){
    Node<ValueType>* remove_ptr=head_ptr; //Remember a node to remove
    if(head_ptr==NULL);
    else{
      head_ptr=head_ptr->nextLink();
      if(head_ptr!=NULL)
        head_ptr->set_prevLink(NULL);
      delete remove_ptr;
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Postcondition: A node pointed to by prev_node has been removed
  // from the list and its storage returned to the freestore
  template<class ValueType>
  void list_remove(Node<ValueType>* prev_ptr){
    if(prev_ptr==NULL||prev_ptr->nextLink()==NULL){;}
    else{
      Node<ValueType>* remove_ptr=prev_ptr->nextLink();
      if(prev_ptr->nextLink()->nextLink()==NULL){//remove tail
        delete prev_ptr->nextLink();
        prev_ptr->set_nextLink(NULL);
      }else{ //remove a node between two nodes
        prev_ptr->set_nextLink(remove_ptr->nextLink());
        remove_ptr->nextLink()->set_prevLink(remove_ptr->prevLink());
        delete remove_ptr;
      }
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Postcondition: All nodes have been removed, returned to the freestore
  template<class ValueType>
  void list_clear(Node<ValueType>*& head_ptr){
    while(head_ptr!=NULL)
      list_head_remove(head_ptr);
  }

  // Precondition: head_ptr points to the head of a linked list
  // The pointer variable in the last node is NULL
  // Postcondition: head_ptr points to a duplicate of list pointed to by source_ptr
  // Duplicated list is nodes created by dynamic allocation
  template<class ValueType>
  void list_copy(Node<ValueType>* source_ptr, Node<ValueType>*& head_ptr){
    if(source_ptr==NULL)
      head_ptr=NULL;
    else{
      head_ptr=new Node<ValueType>(source_ptr->get_data());
      for(int i=1;i<list_length(source_ptr);i++)
        list_insert(list_locate(head_ptr,i), list_locate(source_ptr,i+1)->get_data());
    }
  }

  // Precondition: head_ptr points to the head of a linked list
  // Postcondition: print all nodes' data from the head
  template<class ValueType>
    void show_nodes_head(const Node<ValueType>* head_ptr){
      const Node<ValueType>* cursor=head_ptr;
      for(size_t i=1;i<=list_length(head_ptr);i++){
        cout<<cursor->get_data()<<" ";
        cursor=cursor->nextLink();
      }
      cout<<'\n';
    }
} // linkedList

#endif // NODE_H_