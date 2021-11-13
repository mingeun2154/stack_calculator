// 2018203023 Mingeun Park
// This is interface&implementation for MyStack class.

#ifndef _MYSTACK__H_
#define _MYSTACK__H_

#include <assert.h>
#include "node.h"
using namespace linkedList;

namespace mystack
{
  template <class Item>
  class Stack
  {
  public:
    Stack() { top_ptr = NULL; }
    
    Stack(Item data) 
    { top_ptr = new Node<Item>(data); }

    // copy constructor
    Stack(const Stack<Item> &source) 
    { list_copy(source.top_ptr, &this->top_ptr); }

    void push(const Item &entry)
    { list_head_insert(&top_ptr, entry); }

    void pop(){
      assert(!this->empty()); // Check underflow
      list_head_remove(&top_ptr);
    }
    
    bool empty(){
      return top_ptr == NULL;
    }

    Item top() const{
      assert(!this->empty());
      return top_ptr->get_data();
    }

  private:
    Node<Item> *top_ptr;
  }; // Stack

} // namespace mystack

#endif