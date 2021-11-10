// 2018203023 Mingeun Park
// This is interface for MyStack class.

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include "node.h"
using namespace linkedList;

namespace mystack
{
  template<class ValueType>
  class Stack{
    public:
      Stack() { top_ptr = NULL; }
      Stack(ValueType data);
      Stack(const Stack<ValueType> &source);

      void push(const ValueType &entry);
      void pop();
      bool empty();
      ValueType top() const;

    private:
      Node<ValueType> *top_ptr;
  };
  
} // namespace mystack

#endif