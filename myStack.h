// 2018203023 Mingeun Park
// This is interface&implementation for MyStack class.

#ifndef _MYSTACK__H_
#define _MYSTACK__H_

#include <assert.h>
#include <stdlib.h>
#include "node.h"
using namespace linkedList;

namespace mystack
{
  template <class Item>
  class Stack{
  public:
    Stack() { top_ptr = NULL; }
    
    Stack(Item data) 
    { top_ptr = new Node<Item>(data); }

    // copy constructor
    Stack(const Stack<Item> &source){
      if(source.top_ptr==NULL)
        this->top_ptr=NULL;
      else{
        top_ptr=new Node<Item>(source.top_ptr->get_data());
        for(int i=1;i<list_length(source.top_ptr);i++)
          list_insert(list_locate(this->top_ptr,i), list_locate(source.top_ptr,i+1)->get_data());
      }
    }

    void push(const Item &entry){
      if(this->is_empty()){
        this->top_ptr = new Node<Item>(entry);
      }
      else{
        Node<Item>* original_top=this->top_ptr;
        this->top_ptr=new Node<Item>(entry, NULL, this->top_ptr); // insert new item(node)
        original_top->set_prevLink(this->top_ptr);
      }
    }

    void pop(){
      assert(top_ptr!=NULL); // check underflow
      Node<Item>* remove_ptr=this->top_ptr; //Remember a node to remove
      if(remove_ptr==NULL);
      else{
        this->top_ptr=(this->top_ptr)->nextLink();
        if(this->top_ptr!=NULL)
          (this->top_ptr)->set_prevLink(NULL);
        delete remove_ptr;
      }
    }
    
    bool is_empty(){
      return top_ptr == NULL;
    }

    Item top() const{
      assert(top_ptr!=NULL);
      return top_ptr->get_data();
    }

  private:
    Node<Item> *top_ptr;
  }; // Stack

} // namespace mystack

#endif